#ifndef QUEST_TEST_H
#define QUEST_TEST_H
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
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

     void inputAnswer(ofstream &fout);
     void inputQuestion(ofstream &fout);
     void addTicket(vector<Ticket> &questions, ofstream &fout);
};
void runQuest(vector<Ticket> &questions, Person &person, Ticket &ticket, ifstream &fin);

#endif //QUEST_TEST_H
