 /*
  Chapter 2 Part 6 
 Implementations tasks
 
 tasks
 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Wait for my code review.
 */
 
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
  bool isInCollection = true;
  
  void favorite();
};

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
