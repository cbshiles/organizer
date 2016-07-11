#include <string>
#include <iostream>
#include <ctime>

using namespace std;

struct Date {
  int x;
  tm *t;
  time_t tt;
  Date(){
    tt = time(0);
    t  = gmtime(&tt);
  }

  Date(int year, int month, int day){
    t = new tm();
    t->tm_year = year-1900;
    t->tm_mon = month-1;
    t->tm_mday = day;

    t->tm_hour = 0;
    t->tm_min = 0;
    t->tm_sec = 0;
    
    tt = mktime(t);
  }

  string tos(){
    return to_string(t->tm_year+1900)+'/'+to_string(t->tm_mon+1)+'/'+to_string(t->tm_mday);
  }

  time_t dr(time_t ti){ //round date to nearest day (cut off hours mins and sec)
    return ti - (ti%(24*60*60));
  }

  int diff(Date *od){
    return (int) ((dr(this->tt) - dr(od->tt))/(24*60*60)); //seconds in day
  }
};

#define test(s) ut.call(s, #s) 

struct UnitTest {

  UnitTest(){
    valid = 1;
  }

  int valid;
  
  void call(int truth, string str){
    valid &= truth;
    if (!truth){
      cout << "Test failed: "+str+"\n";
    }
  }

  void finish(){
    printf("All the tests were%s passed\n", valid?"":" not");
  }
};
