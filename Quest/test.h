#ifndef QUEST_TEST_H
#define QUEST_TEST_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Person{
public:
    int score;
    int answer;
    Person(){
        score = 0;
    }

};
class Ticket{
public:
     bool stop_word;
     int number;
     string question;
     string answer[3];
     int answer_correct_number;
     Ticket(){
         number = 0;
         stop_word = true;
     }

     void inputAnswer();
     void inputQuestion();
     void addTicket(vector<Ticket> &questions);
};
void runQuest(vector<Ticket> &questions, Person &person, Ticket &ticket);

#endif //QUEST_TEST_H
