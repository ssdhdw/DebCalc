#include <iostream>
#include <string>
#include <vector>
#include "getch.h"

using namespace std;

bool canUse(char c) 
{
  if ( (c > 46 && c < 58) || c == 32 || c == '\n' || c == 42 || c == 43 || c == 45   || c == 47 || c == 61) return true;
  return false;
}

int eval(int num1,int num2,char op) 
{
  if (op == 42)
  return num1 * num2;

  if (op == 43)
  return num1 + num2;

  if (op == 45)
  return num1 - num2;

  if (op == 47)
  return num1 / num2;

  return 0;
}

int main() 
{
  string s;
  vector <int> numbers;
  vector <char> operations;
  string tempNum = "";
  
  while (true) 
  {
    char c = getch();
    if (c == 27) break;
    if (c == '\n')
    {
      cout << c;
      continue;
    }
    if (canUse(c))
    {
      if (c == 61) 
      {
        cout << "= ";
        for (char c2 : s) 
        {
          if (c2 == 32) continue;
          if (c2 > 47 && c2 < 58)
          {
            tempNum += c2;
            continue;
          }
          if (tempNum == "") 
          {
            operations.pop_back();
            operations.push_back(c2);
          } else 
          {
            numbers.push_back(stoi(tempNum));
            operations.push_back(c2);
            tempNum = "";
          }
        }
        numbers.push_back(stoi(tempNum));
        int out = numbers[0];
        for (int i = 1; i < numbers.size(); i ++)
        {
          out = eval(out, numbers[i], operations[i - 1]);
        }
        cout << out;
        s = "";
        tempNum = "";
        operations.clear();
        numbers.clear();
      } 
      else 
      {
        s += c;
        cout << c;
      }
    }
  }
  return 0;
} 