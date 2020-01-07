 /*
  Chapter 2 Part 6 
 Implementations tasks
 
 tasks
 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */
struct Limb
{
  float stepSize();
  void stepForward();
  unsigned int totalStepsTaken = 0;
};

float Limb::stepSize()
{
  return 2.5f;
}

void Limb::stepForward()
{
  totalStepsTaken += 1;
}

struct Person
{
  Limb leftFoot;
  Limb rightFoot;

  int age;
  int height;
  float hairLength;
  float GPA;
  unsigned int SATScore;
  float distanceTraveled = 0;
  float timeTraveled = 0;

  void run(int, bool);
};

void Person::run(int howNotSlow, bool startWithLeftFoot)
{
  if (startWithLeftFoot == true )
  {
    leftFoot.stepForward();
    rightFoot.stepForward();
  }
  else
  {
    rightFoot.stepForward();
    leftFoot.stepForward();
  }
  distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();
  timeTraveled += howNotSlow;
}

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
  bool isCheckedOut = false;

  void writeInBook(Paper, unsigned int);
};

void Book::writeInBook(Paper page, unsigned int pagesWritten = 1)
{
  page.hasWriting = true;
  numberOfPages += pagesWritten;
}
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
  bool buyLibraryCard();
};

void Library::checkOutBook(Book book)
{
  book.isCheckedOut = true;
  numberOfBooksAvailable -= 1;
  numberOfBooksCheckedOut += 1;
}

bool Library::buyLibraryCard()
{
  if (isOpen)
  {
    return true;
  }
  else
  {
    return false;
  }
}
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
  bool isPlaying = false;
  bool hasMovie = false;
  Movie currentMovie;

  void pressPowerButton();
  void changeMovie(Movie);
  void play();
  void pause();
  void stop();
  void rewind();
  void fastForward();
};

void VCR::pressPowerButton()
{
  if (isTurnedOn == true)
  {
    isTurnedOn = false;
  }
  else
  {
    isTurnedOn = true;
  }
}

void VCR::changeMovie(Movie movie)
{
  currentMovie = movie;
}

void VCR::play()
{
  isPlaying = true;
  if (currentMovie.isRewound)
  {
    currentMovie.isRewound = false;
  }
}

void VCR::pause()
{
  isPlaying = false;
}

void VCR::stop()
{
  pause();
}

void VCR::rewind()
{
  if (isPlaying)
  {
    isPlaying = false;
  }
  currentMovie.isRewound = true;
}

void VCR::fastForward()
{
  if (isPlaying)
  {
    isPlaying = false;
    if (currentMovie.isRewound)
    {
     currentMovie.isRewound = false;
    }
  }
}
/*
 6)
 */
struct Television
{
  bool isOn = false;
  unsigned int currentChannel = 3;
  float screenSizeInInches = 22.5;
  unsigned int volume = 14;

  struct RemoteControl
  {
    bool hasBatteries = true;
    
    void pressPowerButton(Television);
    void changeChannel(Television, unsigned int);
    void changeVolume(Television, int);
  };

  RemoteControl remote;

  void pressPowerButton();
  void changeChannel(unsigned int);
  void changeVolume(int);
};

void Television::pressPowerButton()
{
  if (isOn)
  {
    isOn = false;
  }
  else
  {
    isOn = true;
  }
}

void Television::changeChannel(unsigned int channel)
{
  currentChannel = channel;
}

void Television::changeVolume(int amount)
{
  if (volume + amount <= 0)
  {
    volume = 0;
  }
  else if (volume + amount >= 100)
  {
    volume = 100;
  }
  else
  {
    volume += amount;
  }
}

void Television::RemoteControl::pressPowerButton(Television tv)
{
  tv.pressPowerButton();
}

void Television::RemoteControl::changeChannel(Television tv,unsigned int channel)
{
  tv.changeChannel(channel);
}

void Television::RemoteControl::changeVolume(Television tv, int amount)
{
  tv.changeVolume(amount);
}
/*
 7)
 */
struct Speaker
{
  bool isOn = false;
  unsigned int dB = 90;
  unsigned int frequencyRangeLowHz = 20;
  unsigned int frequenctRangeHighKhz = 20;

  void pressPowerButton();
};

void Speaker::pressPowerButton()
{
  if (isOn)
  {
    isOn = false;
  }
  else
  {
    isOn = true;
  }
}
/*
 8)
 */
struct EntertainmentCenter
{
  VCR vcr;
  Television tv;
  Speaker speaker;

  void pressPowerButton();
};

void EntertainmentCenter::pressPowerButton()
{
  vcr.pressPowerButton();
  tv.pressPowerButton();
  speaker.pressPowerButton();
}
/*
 9)
 */
struct TimeMachine
{
  int currentYear = 2020;
  int startYear = currentYear;
  double quantumLeakagePercentage = 0.0;
  bool paradoxThresholdCrossed = false;
  int estimatedOffsetInYears = 0;
  
  bool travelInTime(int);
  bool returnToCurrentYear();
};

bool TimeMachine::travelInTime(int year)
{
  if (currentYear > year)
  {
    estimatedOffsetInYears += currentYear - year;
  }
  else
  {
    estimatedOffsetInYears += year - currentYear;
  }
  quantumLeakagePercentage += estimatedOffsetInYears / 101;

  if (currentYear + quantumLeakagePercentage > currentYear + 42)
  {
    paradoxThresholdCrossed = true;
  }

  if (paradoxThresholdCrossed)
  {
    currentYear = year + quantumLeakagePercentage;
    return false;
  }
  else
  {
    currentYear = year;
    return true;
  }
}

bool TimeMachine::returnToCurrentYear(){
  if (paradoxThresholdCrossed)
  {
    currentYear = 1570505499;
    startYear = 420972913;
    return false;
  }
  else
  {
    currentYear = startYear;
    return true;
  }
}
/*
 10)
 */
struct Song
{
  unsigned int bpm = 120;
  float timeInMinutes = 7.31f;
  unsigned int releaseYear = 2018;
  bool isInCollection = false;
  
  void favorite();
};

void Song::favorite()
{
  isInCollection = true;
}

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
