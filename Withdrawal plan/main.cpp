#include <bits/stdc++.h>
using namespace std;

// Function to speed up input/output operations
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// Function to calculate the Euclidean distance between two points (x1, y1) and (x2, y2)
double CalculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void solve() {
    int n; cin >> n; // Number of troops
    double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2; // Coordinates of two points defining the super safe line
    vector<pair<double, double>> v(n); // Vector to store the coordinates of the troops

    // Read the coordinates of the troops
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    // Calculate the slope (m) of the super safe line using the formula: m = (y2 - y1) / (x2 - x1)
    double m = (y2 - y1) / (x2 - x1);
    // Calculate the y-intercept (c) of the super safe line using the formula: c = y1 - m * x1
    double c = y1 - m * x1;

    // Initialize the search range for the parameter t (used to parameterize the line)
    double l = -1e9, r = 1e9; // Wide range to cover all possible points on the line
    double distance = 1e18; // Variable to store the minimum total distance => initialize it with maximum number

    // Ternary search to find the optimal point on the line that minimizes the total distance
    while (fabs(l - r) >= 1e-6) {
        // Divide the search range into three parts
        double m1 = l + (r - l) / 3; // First third point
        double m2 = r - (r - l) / 3; // Second third point

        // Calculate the corresponding y-coordinates for m1 and m2 on the line
        double yy1 = m * m1 + c; // y-coordinate for m1
        double yy2 = m * m2 + c; // y-coordinate for m2

        // Calculate the total distance for all troops to reach (m1, yy1) and (m2, yy2)
        double dist1 = 0, dist2 = 0;
        for (int i = 0; i < n; i++) {
            dist1 += CalculateDistance(v[i].first, v[i].second, m1, yy1); // Distance to (m1, yy1)
            dist2 += CalculateDistance(v[i].first, v[i].second, m2, yy2); // Distance to (m2, yy2)
        }

        // Update the search range based on which point gives a smaller total distance
        if (dist1 >= dist2) {
            l = m1; // Move the left boundary to m1
            distance = dist2; // Update the minimum distance
        } else {
            r = m2; // Move the right boundary to m2
            distance = dist1; // Update the minimum distance
        }
    }

    cout << fixed << setprecision(6) << distance << "\n";

    // Output the optimal meeting point (x, y) on the super safe line with 6 decimal places
    // The x-coordinate is the average of the final search range (l and r)
    // The y-coordinate is calculated using the line equation: y = m * x + c
    cout << fixed << setprecision(6) << (l + r) / 2 << " " << m * ((l + r) / 2) + c << "\n";
}

int main() {
    fastIO();
    solve();
    return 0;
}