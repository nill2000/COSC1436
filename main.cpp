#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void getData(fstream& inf, string names[], double runData[][8], int count);
void _getAverage(double runData[][8], int count);
void _print(string names[], double runData[][8], int count);

int main(){
    int namesAmount = 5;
    string names[namesAmount];
    double runData[namesAmount][8];
    fstream inFile;

    getData(inFile, names, runData, namesAmount);
    getAverage(runData, namesAmount);
    // print(names, runData, namesAmount);
    return 0;
}

void getData(fstream& inf, string names[], double runData[][8], int count){
    inf.open("data.txt");

    for (int i = 0; i < count && inf >> names[i]; i++){
        inf >> runData[i][0] >> runData[i][1] >> runData[i][2]
            >> runData[i][3] >> runData[i][4] >> runData[i][5]
            >> runData[i][6] >> runData[i][7];
    }
    
    inf.close();
}

void getAverage(double runData[][8], int count){
    double average;
    string dayName;

    for (int days = 0; days < 7; days++){
        double miles = 0;
        for (int names = 0; names < count; names++){
            miles += runData[names][days];
        }

        switch(days){
            case 0:
                dayName = "Sunday";
                break;
            case 1:
                dayName = "Monday";
                break;
            case 2:
                dayName = "Tuesday";
                break;
            case 3:
                dayName = "Wednesday";
                break;
            case 4:
                dayName = "Thursday";
                break;
            case 5:
                dayName = "Friday";
                break;
            case 6:
                dayName = "Saturday";
                break;
        }
        
        average = miles / count;
        cout << "Day: " << dayName << " Average: " << average << endl;
    }
}

void print(){

}