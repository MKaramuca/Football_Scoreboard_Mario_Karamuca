//Dr. Tyson McMillan a Soccer Scoreboard using 
//Object Oriented Programming in C++
//Updates 4-21-2021 - Dr_T
//Dr_T teaching Object Oriented Scoreboard in C++ 

#include <iostream>
#include <string> 
#include <unistd.h>
#include "Input_Validation_Extended.h"
using namespace std; 


class Team 
{
  private:
    // int score; 
    // bool homeStatus; 
    // string name; 
    // int shotsOnGoal; 
    // string coachName; 
    string name;
    string Coach_Name;
    string Home_City;
    bool homeStatus;
    int score;
    int Timeout_Count;
  public:

      Team(){
        score = 0;
        homeStatus = false;
        name = "Team";
        Coach_Name = "DefaultCoachName";
        Home_City = "City";
        Timeout_Count = 3;
      }
      
      void setScore(int s){
        score = s;
      }
      void setHomeStatus(bool hs){
        homeStatus = hs;
      }
      void setCoach_Name(string cn){
        Coach_Name = cn;
      }
      void setHome_City(string hc){
        Home_City = hc;
      }
      void setName(string teamName){
        name = teamName;
      }
      //adds 7 to the score
      void scoreTouchdown(){
        score += 7;
      }
      //adds 3 to the score
      void scoreFG (){
        score += 3;
      }
      void setTimeoutCount (int to) {
        Timeout_Count = to;
      }
      //takes away a timeout
      void callTimeOut (){
        Timeout_Count --;
      }
      int getTOs (){
        return Timeout_Count;
      }

      int getScore() const{
        return score;
      }
      bool getHomeStatus() const{
        return homeStatus;
      }

      string getName() const {
        return name;
      }
      string getCoachName() const {
        return Coach_Name;
      }
      string getHome_City() const {
        return Home_City;
      }
};

class Scoreboard
{
  private:
    int quarter; 
    Team home; //object that is a member of anothe object
    Team visitor; 
    bool ballPosession;
    string timeLeft;
    int downs;
    int yardsToGo;
  public: 
    Scoreboard()
    {
      quarter = 1; 
      timeLeft = "12:00";
      ballPosession = true;
      downs = 1;
      yardsToGo = 10;
    }  
    void setHalf(int h) { quarter = h; }
    void setHome(Team hSet) { home = hSet; }
    void setVisitor(Team vSet) { visitor = vSet; }
    void setDowns(int d){ downs = d; }
    void setYTG (int y){ yardsToGo = y; }
    int getQuarter() const { return quarter; }
    Team getHome() const { return home; }
    Team getVisitor() const { return visitor; }

    void nextQuarter (){
      quarter ++;
      timeLeft = "12:00";
    }
    string getTime(){
      return timeLeft;
    }
    bool getPosession (){
        return ballPosession;
      }

      void changePos (){
        if(ballPosession){
          ballPosession = false;
        }
        else{
          ballPosession = true;
        }
      }

      void setTimeLeft (string t){
        timeLeft = t;
      }


    void showScoreboard()
    {
      

      

      string color = ""; 
      string reset = "\x1b[0m";
      color = "\x1b[32;4m"; //green 
      string score = "\x1b[36;1m"; //score color
      string sbc = "\x1b[33;1m"; //score color 

      cout << color << "Football Scoreboard Mario K Sytle" << reset << endl; 
      cout << sbc << "Time Remaining: " << timeLeft << " \tQuarter: " << quarter << endl;
      cout << score << home.getHome_City() << " - " << home.getName() << "\t\t" << reset << visitor.getHome_City() <<  " - "  << visitor.getName() << endl; 
      cout << "\t" << score << home.getScore() << reset << "\t\t\t\t\t\t\t" << visitor.getScore() << endl; 
      cout << score << home.getCoachName() << reset << "\t\t\t\t\t" << visitor.getCoachName() << endl; 

      cout << sbc << "\tDown: " << downs << "\t\t\t\t Yards: " <<yardsToGo << reset << endl;

      //asume home team starts with ball - no cointoss, etc.
      if(ballPosession){
        cout << sbc << "Home <>  Visitor ___" << reset << endl;
      }
      else{
        cout << sbc << "Home ___ Visitor <> " << reset << endl;
      }
      cout << sbc <<"Timeouts left - " << score << "Home: " <<  home.getTOs() << reset << " Visitor: " << visitor.getTOs() << endl;
      

      for(int i = 0; i < 40; i++) { cout << "*"; } cout << endl;
       
       //proces to show the home team status
       cout << "Home> \t"; 
       if(home.getHomeStatus() == true)
       {
         cout << "Team 1: " << home.getName() << "*"; 
       }
       else if(visitor.getHomeStatus() == true)
       {
         cout << "Team 2: " << visitor.getName() << "*"; 
       }
       else
       {
         cout << "Error: "; 
       }
       
       cout  << endl; 
    }
};

int main() 
{
  Scoreboard s;
  Team tOne;
  Team tTwo; 
  string newName = ""; 
  char userChoice; 
  string newCoachName = ""; 
  int homeTeamQuestion = 0; 
  int newScore = 0; 

  //Set the home team 
  tOne.setHomeStatus(true); //tOne is the Home Team now   

  //add some initial data to s
  s.setHome(tOne); 
  s.setVisitor(tTwo); 

  //Loop this to make it an interactive menu

  do 
  {
    //thought it would be more interesting to set scores and add quarters rather than just automatically input
    //gives the opportunity to excercise different function inputs and incrementors in the class' within each other, but could have done either way.
    //timeouts could have been set to be unable to be called when at 0, and this could have been more of a user set scoreboard rather than game specific
      system("clear"); //clear the screen of previous content 
      s.showScoreboard(); //show the current scoreboard data
      //menu choices 
      cout << "A = Update Home Team Name" << endl; 
      cout << "B = Update Home Coach Name" << endl; 
      cout << "C = Update Home Team City" << endl; 
      cout << "D = Update Visiting Team Name" << endl; 
      cout << "F = Update Visiting Coach Name" << endl; 
      cout << "G = Update Visiting Team City" << endl;
      cout << "H = Update Home Status" << endl;
      cout << "I = Home Team timeout!" << endl;
      cout << "J = Home Visiting timeout!" << endl;

      cout << "K = Home Team touchdown!" << endl;
      cout << "L = Visiting Team touchdown!" << endl;
      cout << "M = Home Team field goal!" << endl;
      cout << "N = Visiting Team field goal!" << endl;
      cout << "O = Next Quarter" << endl;
      cout << "P = Change ball posession" << endl;
      cout << "Q = Set the time left in the quarter" << endl;
      cout << "R = Set the yards to go" << endl;
      cout << "S = Set the down" << endl;
      cout << "T = Set the Home teams score" << endl;
      cout << "U = Set the Visiting teams score" << endl;
      //this could have been done with timeouts, but wanted to show both methods.





      cout << "E = Exit" << endl;
      cout << ">"; 
      userChoice = validateChar(userChoice);

      if(userChoice == 'a' || userChoice == 'A'){
        cout << "*****Updated Home Team Name*****" <<endl;
        cout << "\nPlease enter a new name for the home team: ";
        newName = validateString(newName);
        tOne.setName(newName);
      }
      else if(userChoice == 'b' || userChoice == 'B'){
        cout << "*****Updated Home Coach Name*****" <<endl;
        cout << "\nPlease enter a new name for the home coach: ";
        newName = validateString(newName);
        tOne.setCoach_Name(newName);
      }
      if(userChoice == 'C' || userChoice == 'c'){
        cout << "*****Updated Home Team City*****" <<endl;
        cout << "\nPlease enter a new name for the home city: ";
        newName = validateString(newName);
        tOne.setHome_City(newName);
      }
      else if(userChoice == 'd' || userChoice == 'D'){
        cout << "*****Updated Visitng Team Name*****" <<endl;
        cout << "\nPlease enter a new name for the visiting team: ";
        newName = validateString(newName);
        tTwo.setName(newName);
      }
      else if(userChoice == 'f' || userChoice == 'F'){
        cout << "*****Updated Visiting Coach Name*****" <<endl;
        cout << "\nPlease enter a new name for the visiting coach: ";
        newName = validateString(newName);
        tTwo.setCoach_Name(newName);
      }
      else if(userChoice == 'g' || userChoice == 'G'){
        cout << "*****Updated Visiting City Name*****" <<endl;
        cout << "\nPlease enter a new name for the Visiting city: ";
        newName = validateString(newName);
        tTwo.setHome_City(newName);
      }
      else if(userChoice == 'H' || userChoice == 'h')
      {
        cout << "\nUpdate Home Status Module****" << endl; 
        cout << "\nWho is the home team: 1 = T1, 2=T2: "; 
        homeTeamQuestion = validateInt(homeTeamQuestion); 
       // cin >> homeTeamQuestion; 
        if(homeTeamQuestion == 1)
        {
          tOne.setHomeStatus(true); 
          tTwo.setHomeStatus(false); 
        }
        else if(homeTeamQuestion == 2)
        {
          tOne.setHomeStatus(false); 
          tTwo.setHomeStatus(true);
        }
        else
        {
          cout << "\nInvalid Input!" << endl;
          sleep(2); 
        }
      }
      else if(userChoice == 'I' || userChoice == 'i'){
        tOne.callTimeOut();
      }
      else if(userChoice == 'J' || userChoice == 'j'){
        tTwo.callTimeOut();
      }
      else if(userChoice == 'K' || userChoice == 'k'){
        tOne.scoreTouchdown();
      }
      else if(userChoice == 'L' || userChoice == 'l'){
        tTwo.scoreTouchdown();
      }
      else if(userChoice == 'M' || userChoice == 'm'){
        tOne.scoreFG();
      }
      else if(userChoice == 'N' || userChoice == 'n'){
        tTwo.scoreFG();
      }
      else if(userChoice == 'O' || userChoice == 'o'){
        if(s.getQuarter() == 2){
          tOne.setTimeoutCount(3);
          tTwo.setTimeoutCount(3);
        }
        s.nextQuarter();
      }
      else if(userChoice == 'P' || userChoice == 'p'){
        s.changePos();
        s.setDowns(1);
        s.setYTG(10);
        //assumption that not near goal, etc.
      }
      else if(userChoice == 'Q' || userChoice == 'q'){
        cout << "Enter the time left in the following format: MM:SS" << endl;
        string temp;
        temp = validateString(temp);
        s.setTimeLeft(temp);
      }
      else if(userChoice == 'r' || userChoice == 'R'){
        cout << "Enter the yards to go until first down: " << endl;
        int temp;
        temp = validateInt(temp);
        s.setYTG(temp);
      }
      else if(userChoice == 'S' || userChoice == 's'){
        cout << "Enter what down it is (1-4): " << endl;
        int temp;
        temp = validateInt(temp);
        s.setDowns(temp);
      }
      else if(userChoice == 'T' || userChoice == 't'){
        cout << "Enter the exact score you would like to set for the Home team: " << endl;
        int temp;
        temp = validateInt(temp);
        tOne.setScore(temp);
      }
      else if(userChoice == 'U' || userChoice == 'u'){
        cout << "Enter the exact score you would like to set for the Visiting team: " << endl;
        int temp;
        temp = validateInt(temp);
        tTwo.setScore(temp);
      }
      
      else if(userChoice == 'e' || userChoice == 'E')
      {
        cout << "Exit chosen." << endl; 
      }
      else //invalid input: default clause
      {
        cout << "\nInvalid input." << endl; 
        sleep(2); //wait two seconds, go to the next process 
      }


      s.setHome(tOne); //refresh the data in s to the new updates...
      s.setVisitor(tTwo); //refresh the data
  
  }while(userChoice != 'e' && userChoice != 'E');


  return 0; 
}