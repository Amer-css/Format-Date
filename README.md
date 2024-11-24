Format Date is a powerful C++ program for parsing, validating, and formatting dates. With multiple formatting options, it allows users to display dates in creative and customizable ways.

![DateMaster Preview](29509458.jpg)

---

## 🚀 Features
- Parse dates from a string (e.g., `dd/mm/yyyy`).
- Validate date formats to ensure correctness.
- Convert dates to various styles, including:
  - Traditional formats: `dd/mm/yyyy`, `mm-dd-yyyy`.
  - Creative styles: Circle, ASCII box, Emojis, Timeline.
- Replace and customize date strings easily.

---

## 📂 How to Use
1. Clone the repository:
   ```bash#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct sDate {
    short Year;
    short Month;
    short Day;
};

vector<string> SplitStringByDelimiter(string S1, string Delim) {
    vector<string> vString;
    short pos = 0;
    string sword;

    while ((pos = S1.find(Delim)) != string::npos) {
        sword = S1.substr(0, pos);
        if (sword != "") {
            vString.push_back(sword);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "") {
        vString.push_back(S1);
    }
    return vString;
}

string ConvertDateToString(sDate Date) {
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

sDate ParseDateFromString(string DateString) {
    sDate Date;
    vector<string> vDate = SplitStringByDelimiter(DateString, "/");
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);
    return Date;
}

string ReplaceWordInString(string S1, string stringToReplace, string sReplace) {
    short pos = S1.find(stringToReplace);

    while (pos != string::npos) {
        S1 = S1.replace(pos, stringToReplace.length(), sReplace);
        pos = S1.find(stringToReplace);
    }
    return S1;
}

bool IsValidDate(string DateString) {
    vector<string> dateParts = SplitStringByDelimiter(DateString, "/");

    if (dateParts.size() != 3) {
        return false;
    }

    int day = stoi(dateParts[0]);
    int month = stoi(dateParts[1]);
    int year = stoi(dateParts[2]);

    if (day < 1 || day > 31 || month < 1 || month > 12) {
        return false;
    }

    return true;
}

string ReadString(string Message) {
    string formatDate;
    cout << Message;

    getline(cin >> ws, formatDate);
    while (!IsValidDate(formatDate)) {
        cout << "Error: Invalid date format. Please enter in the format dd/mm/yyyy.\n";
        getline(cin >> ws, formatDate);
    }
    return formatDate;
}

string FormatDate(sDate Date, string DateFormat = "dd/mm/yyyy") {
    string FormattedDate = DateFormat;

    if (DateFormat == "mm-dd-yyyy") {
        FormattedDate = "?? " + to_strin
ذذذ
   git clone https://github.com/your-username/DateMaster.git
   cd DateMaster
```

## 🖥️ Output Preview
Here is a preview of the program's output after running it:

![Program Output](Date.png)
