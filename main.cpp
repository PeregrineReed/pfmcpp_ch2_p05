/*
 
 Chapter 2 Part 5 Task:
 User-Defined Types
 
 1) write 10 user-defined types, each with a random number of member variables
    try to make the member variables have names that are related to the user-defined type.
 
 2) give the member variables relevant data types
 
 3) add a couple member functions.  
    make the function parameter list for those member functions use some of your User-Defined Types
 
 4) make 2 of the 10 user-defined types be nested class
 
 5) One of your UDTs should only use UDTs for its member variable types.   
     No primitives allowed!
 
 6) After you finish defining each type, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Wait for my code review.
 */

/*
 example:
 */
struct CarWash            //1) a U.D.T. with a random number of member variables
{
    int numSponges = 3;
    double amountOfSoapUsedPerCar = 2.6; //2) relevant data types
    unsigned int numCarsProcessed = 0;
    
    struct Car                             //4) nested class
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        //2) relevant data types
    };
    
    void washAndWaxCar( Car car );         //3) member function with a user-defined type as the parameter.  The user-defined type parameter happens to be the nested class.
    
    Car myCar;  //5) a member variable whose type is a UDT.
};


/*
 1)
 */
struct Paper
{
  bool hasWriting = false;
  unsigned int heightInInches = 14;
  unsigned int lengthInInches = 10;
};
/*
 2)
 */
struct Book
{
  unsigned int numberOfPages = 100;
  bool hardcover = true;
  float rating = 4.5f;

  void writeInBook(Paper page, unsigned int pagesWritten = 1);
};
/*
 3)
 */
struct Library
{
  unsigned int totalNumberOfBooks = 500;
  unsigned int numberOfBooksAvailable = 450;
  unsigned int numberOfBooksCheckedOut = 50;
  float costOfLibraryCard = 2.5f;

  bool isOpen = true;

  struct Librarian
  {
    unsigned int age = 30;
    unsigned int shiftStartUtc = 1200;
    unsigned int shiftEndUtc = 1800;
  };

  Librarian employee;
  void checkOutBook(Book book);
  void buyLibraryCard();
};
/*
 4)
 */
struct Movie
{
  float averageRating = 3.5f;
  unsigned int lengthInMinutes = 120;
  bool isRewound = true;
  FIXME add a member function or two
};
/*
 5)
 */
struct VCR
{
  bool isTurnedOn = false;
  bool hasMovie = false;

  void pressPowerButton();
  void insertMovie(Movie movie);
  void play();
  void pause();
  void stop();
  void rewind();
  void fastForward();
  void eject();
};
/*
 6)
 */
struct Television
{
  float screenSizeInInches = 22.5;
  unsigned int volume = 14;

  struct RemoteControl
  {
    bool hasBatteries = true;
    
    void pressPowerButton();
    void changeChannel(unsigned int channel);
    void changeVolume(int amount);
  };

  RemoteControl remote;

  void pressPowerButton();
  void changeChannel(unsigned int channel);
  void changeVolume(int amount);
};
/*
 7)
 */
struct Speaker
{
  unsigned int dB = 90;
  unsigned int frequencyRangeLowHz = 20;
  unsigned int frequenctRangeHighKhz = 20;

  void pressPowerButton();
};
/*
 8)
 */
struct EntertainmentCenter
{
  VCR vcr;
  Television tv;
  Speaker speaker;
  FIXME add a member function or two
};
/*
 9)
 */
struct TimeMachine
{
  int currentYear = 2020;
  double quantumLeakagePercentage = 0.0;
  bool paradoxThresholdCrossed = false;
  int estimatedOffsetInYears = 0;
  
  bool travelInTime(int year);
  bool returnToCurrentYear();
};
/*
 10)
 */
struct Song
{
  unsigned int bpm = 120;
  float timeInMinutes = 7.31f;
  unsigned int releaseYear = 2018;
  bool IsInCollection = true; FIXME camelCase
  
  void favorite();
};

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
