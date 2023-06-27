#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

string formatTheta(string expression) {
    return "T(n) = \u0398(" + expression + ")\n";
}

string formatNo(float value) {
    if (value == 0) {
        return "";
    } else if (value == 1) {
        return "n";
    } else if (value == (int) value) {
        return "n^" + to_string((int) value);
    } else {
        ostringstream stream;
        stream << fixed << showpoint << setprecision(1) << value;
        return "n^" + stream.str();
    }
}

string formatLog(int k) {
    if (k == 0) {
        return "";
    } else if (k == 1) {
        return "log n";
    } else {
        return "log^" + to_string(k) + " n";
    }
}

string mastertheorem(int a, float b, float c, float d, int k) {
    // case 1
    if ((double) a > pow(b, d)) {
        double power = log(a) / log(b);
        string formatPower = formatNo(power);
        return formatTheta(formatPower);
    }
    // case 2
    else if ((double) a == pow(b, d)) {
        double power = log(a) / log(b);
        string result = formatNo(power);
        string logResult = formatLog(k + 1);
        if (result != "") {
            result += " ";
        }
        result += logResult;
        return formatTheta(result);
    }
    // case 3
    else if ((d > 1) || (((a)/(b)) < c)) {
        string formatD = formatNo(d);
        string formatlg = formatLog(k);
        if (formatD != "" && formatlg != "") {
            formatD += " ";
        }
        formatD += formatlg;
        return formatTheta(formatD);
    } 
    return "not applicable\n";
}

int main() {
    int TC;
    cin >> TC;
    cin.ignore();
    string result = "";

    for (int i = 0; i < TC; i++) {
        int a, k;
        float b, c, d;
        string line;
        getline(cin, line);
        istringstream iss(line);
        iss >> a >> b >> c >> d >> k;

        result += mastertheorem(a, b, c, d, k);
    }
    cout << result;
    return 0;
}
