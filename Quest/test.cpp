#include "test.h"
#include <iostream>
#include <vector>

using namespace std;
void Ticket::inputQuestion(){
    cout << "������� ����� ������� �"<< number + 1 << "\n";
    getline(cin, question);
}

void Ticket::inputAnswer(){
    cout << "������� ����� ������ �1" << "\n";
    getline(cin, answer[0]);
    cout << "������� ����� ������ �2" << "\n";
    getline(cin, answer[1]);
    cout << "������� ����� ������ �3" << "\n";
    getline(cin, answer[2]);
}

void Ticket::addTicket(vector<Ticket> &questions) {
    while(stop_word == 1) {
        questions.push_back(*this);
        questions[this->number].inputQuestion();
        questions[this->number].inputAnswer();
        cout << "������� ����� ����������� ������ \n";
        cin >> questions[this->number].answer_correct_number;
        questions[this->number].answer_correct_number--;
        cout << "��������� ������� ������?|1|0|" << "\n";
        cin >> stop_word;
        this->number++;
    }
}

void runQuest(vector<Ticket> &questions, Person &person, Ticket &ticket){
    for(int i = 0; i < ticket.number; i++) {
        cout << questions[i].question << "\n";
        cout << "1) " << questions[i].answer[0] << "\n";
        cout << "2) " << questions[i].answer[1] << "\n";
        cout << "3) " << questions[i].answer[2] << "\n";
        cout << "������� ��� ����� (�����)\n";
        cin >> person.answer;
        person.answer--;
        if (person.answer == questions[i].answer_correct_number) {
            person.score++;
        }
        cout << "������� " << person.score << "/" << ticket.number << "\n";
    }
    cout << "���������� ���������� �������: "<< person.score <<"\n";

}

