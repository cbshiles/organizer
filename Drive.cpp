#include <stdio.h>
//#include <string>
#include <vector>

#include "Date.h"



struct Goal {
  string title;

  virtual string display(){
    return title+"/n";
  }
  
  void remove();
  // ??? check(); //checks if anything is due today
};

struct ComplexGoal : public Goal{

  string description;
  vector<Goal> parts;
  
};

struct DefiniteGoal : public ComplexGoal{

  Date endPoint;

  //??? complete(); //calls delete at end

  virtual string display(){ //# needs to be re written
    string s = title+"\n"+description+"\n"+endPoint.tos();

    for (unsigned i=0; i < parts.size(); i++) {
      s += "\n\t"+parts[i].display();
    }
    return s;
  }

  // virtual ??? check(){
  //   if (today >= endPoint)
  //     return whole_thing;
  //   else
  //     go through parts;
  // }
  
};

struct IndefiniteGoal : public ComplexGoal{
  virtual string display(){
    string s = title+"\n"+description;

    for (unsigned i=0; i < parts.size(); i++) {
      s += "\n\t"+parts[i].display();
    }
    return s;
  }

  //check()  ... its always relevant, also need tocheck parts

};

void dateTest(){
 UnitTest ut = UnitTest();

 Date tday = Date();
 Date yday = Date(2016, 7, 10);
 Date tmrw = Date(2016, 7, 12);
 
 test(tday.diff(&yday) == 1);
 test(yday.diff(&tmrw) == -2);
 test(tday.diff(&tmrw) == -1);
 ut.finish();
 
}

int main(){
  dateTest();
  return 0;
}
