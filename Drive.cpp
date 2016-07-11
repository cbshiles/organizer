#include <stdio.h>

virtual struct Goal {
  String title;
  virtual string display(){
    printf("%s\n", title);
  }
  void remove();
  // ??? check(); //checks if anything is due today
};

struct ComplexGoal extends Goal{

  string description;
  Goal[] parts;
  
};

struct DefiniteGoal extends ComplexGoal{

  Date endPoint;

  //??? complete(); //calls delete at end

  virtual void display(){
    printf("%s\n%s\n%s", title, description, endPoint);
    for (Goal p in parts){
      printf("\n\t"); p.display();
    }
  }

  // virtual ??? check(){
  //   if (today >= endPoint)
  //     return whole_thing;
  //   else
  //     go through parts;
  // }
  
};

struct IndefiniteGoal extends ComplexGoal{
  virtual void display(){
    printf("%s\n%s", title, description);
    for (Goal p in parts){
      printf("\n\t"); p.display();
    }
  }

  //check()  ... its always relevant, also need tocheck parts

};

int main(){
  printf("pook\n");
  return 0;
}
