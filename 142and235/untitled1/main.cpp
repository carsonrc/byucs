#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void StringSearch(string userString, string searchingString);

int main() {

  string userString;
  const string BFF ("BFF");
  const string IDK ("IDK");
  const string JK ("JK");
  const string TMI ("TMI");
  const string TTYL ("TTYL");

  cout << "Enter text: " << endl;
  getline(cin, userString);
  cout << "You entered : " << userString << endl;

  StringSearch(userString, BFF);
  StringSearch(userString, IDK);
  StringSearch(userString, JK);
  StringSearch(userString, TMI);
  StringSearch(userString, TTYL);

   return 0;
}

 const string BFF ("BFF: best friends forever");
 const string IDK ("IDK: I don't know");
 const string JK  ("JK: just kidding");
 const string TMI ("TMI: too much information");
 const string TTYL("TTYL: talk to you later");

 string output;

void OutputMatcher(string searchingString) {

   if (searchingString == "BFF") {
      output = BFF;
   }
   if(searchingString == "IDK") {
      output = IDK;
   }
   else if(searchingString == "JK") {
      output == JK;
   }
   else if(searchingString == "TMI") {
      output == TMI;
   }
   else if(searchingString == "TTYL") {
      output == TTYL;
   }
   return;
}

void StringSearch(string userString, string searchingString) {

  OutputMatcher(searchingString);

   if (userString.find(searchingString) != string::npos) {
     cout << output << endl;
   }
   return;
}
