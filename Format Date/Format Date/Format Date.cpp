#include <iostream>
#include<string>
#include<vector>
using namespace std;
struct sDate
{
    short Year;
    short Month;
    short Day;
};

vector<string>SplitStringByDelimiter(string S1, string Delim)
{
    vector<string>vString;
    short pos = 0;
    string sword;

    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sword = S1.substr(0, pos);
        if (sword != "")
        {
            vString.push_back(sword);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1);
    }
    return vString;
}
string ConvertDateToString(sDate Date)
{

    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}
sDate ParseDateFromString(string DateString)
{
    sDate Date;
    vector<string>vDate;

    vDate = SplitStringByDelimiter(DateString, "/");
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);


    return Date;
}
string ReplaceWordInString(string S1, string stringToReplace, string sReplace)
{
    short pos = S1.find(stringToReplace);

    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, stringToReplace.length(), sReplace);
        pos = S1.find(stringToReplace);
    }
    return S1;
}
bool IsValidDate(string DateString)
{

    vector<string> dateParts = SplitStringByDelimiter(DateString, "/");

    if (dateParts.size() != 3)
    {
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


string ReadString(string Message)
{
    string formatDate;
    cout << Message;

    getline(cin >> ws, formatDate);
    while (!IsValidDate(formatDate))
    {
        cout << "Error: Invalid date format. Please enter in the format dd/mm/yyyy.\n";
        getline(cin >> ws, formatDate);
    }
    return formatDate;
}
string FormatDate(sDate Date, string DateFormat = "dd/mm/yyyy")
{
    string FormattedDate = DateFormat;

    if (DateFormat == "mm-dd-yyyy")
    {
        FormattedDate = "?? " + to_string(Date.Month) + "-" + to_string(Date.Day) + "-" + to_string(Date.Year);
    }
    else if (DateFormat == "circle")
    {
        FormattedDate =
            "   (" + to_string(Date.Day) + ")\n" +
            "  [" + to_string(Date.Month) + "]\n" +
            " <" + to_string(Date.Year) + ">";
    }
    else if (DateFormat == "ascii_box")
    {
        FormattedDate =
            "+-------------+\n"
            "|  " + to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year) + " |\n" +
            "+-------------+";
    }
    else if (DateFormat == "emoji")
    {
        FormattedDate = "?? " + to_string(Date.Day) + " | ??? " + to_string(Date.Month) + " | ?? " + to_string(Date.Year);
    }
    else if (DateFormat == "timeline")
    {
        FormattedDate =
            "|========== Day " + to_string(Date.Day) +
            " of Month " + to_string(Date.Month) +
            " in Year " + to_string(Date.Year) + " ==========|";
    }
    else
    {
        // Default behavior
        FormattedDate = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
        FormattedDate = ReplaceWordInString(FormattedDate, "mm", to_string(Date.Month));
        FormattedDate = ReplaceWordInString(FormattedDate, "yyyy", to_string(Date.Year));
    }

    return FormattedDate;
}


int main()
{
    string ConvertDateToString = ReadString("\nEnter Date dd/mm/yyyy ");

    sDate Date = ParseDateFromString(ConvertDateToString);

    cout << "\n" << FormatDate(Date) << "\n";
    cout << "\n" << FormatDate(Date, "yyyy/dd/mm") << "\n";
    cout << "\n" << FormatDate(Date, "mm/dd/yyyy") << "\n";
    cout << "\n" << FormatDate(Date, "dd-mm-yyyy") << "\n";
    cout << "\n" << FormatDate(Date, "mm-dd-yyyy") << "\n";
    cout << "\n" << FormatDate(Date, "Day:dd Month: mm Year: yyyy") << "\n";
    cout << "\n" << FormatDate(Date, "circle") << "\n";
    cout << "\n" << FormatDate(Date, "ascii_box") << "\n";
    cout << "\n" << FormatDate(Date, "emoji") << "\n";
    cout << "\n" << FormatDate(Date, "timeline") << "\n";
    cout << "\n" << FormatDate(Date, "dd-mm-yyyy") << "\n";

    return 0;
}


