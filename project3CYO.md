#### **CSCI 1300 CS1: Starting Computing: Project 3 Create-Your-Own**
#### **Godley/Hoefer - Spring 2023**
#### **Due: April 30<sup>th</sup> by 6:00 PM MST**

# Table of contents

- [Table of contents](#table-of-contents)
- [Overview <a name="overview"></a>](#overview-)
- [Collaboration <a name="collaboration"></a>](#collaboration-)
- [Requirements <a name="requirements"></a>](#requirements-)
  - [Feature Requirements <a name="featureReq"></a>](#feature-requirements-)
  - [Implementation Requirements <a name="implementationReq"></a>](#implementation-requirements-)
  - [Group Requirements <a name="groupReq"></a>](#group-requirements-)
- [Extra Credit <a name="ec"></a>](#extra-credit-)
- [Interview Grading <a name="interviewGrading"></a>](#interview-grading-)
- [Timeline <a name="timeline"></a>](#timeline-)
- [Points Summary <a name="points"></a>](#points-summary-)

# Overview <a name="overview"></a>
For the Final Project, you will implement a turn-based, text (adventure) game in C++, or another similar **interactive** concept. The minimum requirements for the project can be found below. From known games, suggested examples include Monopoly, Final Fantasy, and MUD. Of course, you are encouraged to come up with a novel and unique idea in order to distinguish your project from the others.

For the final project, you are allowed to work with (at most) one other student that is currently in CSCI 1300 this semester. You may also choose to work by yourself if you so choose. 

If you choose to work in a group, there are [additional requirements](#groupReq). We expect that you will be contributing to the project equally. **Both group members must submit a zip file for the project**, and the solution files can be the same. Indicate your partner’s name in comments at the top of each code file. **Both partners will book an Interview Grading appointment together and TAs will be grading you individually**.

The following project ideas will **not** be approved:
* Oregon Trail
* Interstellar
* Pokémon
* Tic Tac Toe
* Minesweeper
* Battleship
* Snake
* Chess
* Checkers
* Conway's Game of Life
* Chutes and Ladders
* Card games (e.g., Blackjack)
* Carmen Sandiego

# Collaboration <a name="collaboration"></a>
The collaboration policy outlined in the syllabus applies to this project. As such, **all work for this assignment must be original work**. Every project (group or single) must be original and not similar to ANY other source (internet, paid tutor, fellow student, projects from previous years, etc). You may collaborate and brainstorm with other people, but each assignment submission is to be the unique creation of the author(s). Your code must be original and unique. 

Your work may not include code taken from online resources (e.g. Chegg, StackExchange, etc.) or from other students (past or present), even with modification. Any such instances constitute Academic Dishonesty (passing off others' work as your own) and will earn you a 0 on the assignment and a trip to the Honor Code Council. If a group project is found to be non-unique and deemed worthy of being sent to Honor Code Council then BOTH parties are guilty (even if one party decides to “take the blame”). 

Outside resources (e.g. C++ documentation, StackOverflow, etc.) that are referenced when writing your own solution should be cited explicitly (in code comments, for example). Referencing these types of resources (to, for example, find a specific piece of C++ syntax or understand what an error message means) when writing code is expected; it is not acceptable to use *solutions* (i.e. C++ implementations of algorithms) from any external source, even if they are cited.

**Choose your groups wisely! If you aren’t sure if something is okay, then please ask!**

# Requirements <a name="requirements"></a>

The minimum requirements for this final project are in the following sections. You are **not allowed** to use `stringstream` objects, pointers, or global variables.

In addition to these specific requirements listed below, keep in mind that **choose-your-own projects must be _at least_ as complex as the non-choose-your-own project**. This applies to both implementation complexity and the complexity/richness of features in the game itself.

## Feature Requirements <a name="featureReq"></a>
* The project must have interactive components (ask the player for input values, create menus for choices, and so on). It’s a game! 
* Game stats should be displayed throughout the game. It’s more exciting and meaningful! Also, these stats help debug the code. 
* The project must make use of the provided Map class, the map must be at least 12x12 (see the [project 3 write-up](project3.md) for more information on the Map class). You may choose to write your own 2D Map class or add/remove functionality to/from what’s provided to suit your needs.
* Your project must include: 
    * At least 5 menu options (other than Quit/Exit) 
    * At least two of these options must have a second layer of menu options 
    * At least 2 menu options (primary or secondary layer of the menu) should include a random component, at least one each from the following: 
        * The value of the variable is selected at random from a certain range of values (i.e. select a value at random between 1 and 6) 
        * A probability value determines one of the outcomes (e.g. there is a 60% chance a certain event will occur) 

## Implementation Requirements <a name="implementationReq"></a>
The project must contain (at least) the following:

* A 2D map (in a dedicated class)
* 4+ user defined classes (excluding map class)
    * At least two classes with 4+ data members. 
    * At least one class must include an array/vector of objects from a class that you created.
    * Appropriate methods for each class (including getters, setters, default constructors, and parametrized constructors as needed) 
* 6+ if-else statements 
* 6+ loops (while loops, for loops, do-while, in total) 
* 2+ nested loops 
* File IO (both reading from a file and writing to a file)

## Group Requirements <a name="groupReq"></a>
In addition to the requirements listed above, if you work in a group you must also implement a sorting algorithm and apply it to a task in your program. You should not use a Library function or any external (to this course) resources to implement the sorting algorithm.

One situation where the sorting functionality would be useful is for a ranking task, for example: ranking the number of turns it took each player to reach a final boss.

**Note**: 
- If you work in a team and you do not implement a sorting task, 50 points will be deducted from your point total.
- We expect that you will be contributing to the project equally. **Both group members must submit a zip file for the project**, and the solution files can be the same. Indicate your partner’s name in comments at the top of each code file. Both partners will book an Interview Grading appointment together and TAs will be grading you individually. 


# Extra Credit <a name="ec"></a>

* Dungeon Escape project write-up has three extra-credit opportunities (final battle, persistent scoreboard and resurrection). You may implement similar features to complement your project for 25 extra-credit points.
* Present your project during lecture or through a video. 
  * **Lecture**: A sign-up sheet will be shared a week before class presentations
  * **Video**: Make a 5-minute (+ or - 1 min) video explaining: 
    * The project idea 
    * Implementation and approach 
    * A demonstration of the working project 

# Interview Grading <a name="interviewGrading"></a>

The Project 3 interview grading scheduler will be available on Canvas before the deadline of this project. The
interviews will take place between **May 1<sup>st</sup>** and **May 4<sup>th</sup>**. If you don’t sign-up to meet between **May 1<sup>st</sup>** and **May 4<sup>th</sup>** or you miss your interview, then no points will be awarded for the project. If you work in a group, **both group members should attend the same interview grading slot.**

During the interview grading, TAs will be playing your game and asking conceptual questions. They will also ask about your functionality and implementation.

# Timeline <a name="timeline"></a>

- **April 10<sup>th</sup> – 12<sup>th</sup>: Project design meetings (required).** Meet with professors/TAs to discuss your project ideas and the classes you will create and use. You should bring your class files and code (a list of classes and methods you will implement) to the meeting. During the meeting, we will go over your classes to see if they’re feasible and meet requirements. 
    - Prior to Friday, April 7<sup>th</sup>, you must have reserved a slot on the Project 3 Design Meeting Scheduler and have the meeting date reserved for a day on or before Wednesday April 12<sup>th</sup>.
    - If your project idea gets rejected you have till April 13 <sup>th</sup> to make the suggested changes and submit the class files and skeleton.  

- **Thursday, April 13<sup>th</sup>, 11:59 pm: Submit class files & Code Skeleton.**
  Your `.h` files should be complete with all the data
  members and member functions you will be using for each class. For the
  class implementation `.cpp` files, you should fully implement simple
  functions like your getters and setters. For more complex functions you
  can include function stubs with detailed comments. 

  For example, if we were stubbing a function to implement bubble sort and
  return the number of swaps we might give in our code skeleton: 
  ```c++
  /* 
    1. Compare adjacent elements. If the first is greater than the second,
    swap them. 
    2. Do this for each pair of adjacent elements, starting with the first
    two and ending with the last two. At this point the last element should
    be the greatest. 
    3. Repeat the steps for all elements except the last one. 4. Repeat
    again from the beginning for one less element each time, until there are
    no more pairs to compare. 
  */ 
  int bubble_sort(int arr[], int size) 
  { 
    int swaps = 5; 
    return swaps; // function returns expected type (int) 
  }
  ```

- **Wednesday, April 26<sup>th</sup>, 11:59 pm: Interview Grading Sign-Up deadline**.
  You must sign up for an interview grading timeslot
  no later than **Wednesday, April 26<sup>th</sup> at 11:59 pm**. The
  interviews will take place between **May 1<sup>st</sup>** and
  **May 5<sup>th</sup>**. If you don't sign-up or you miss your
  interview, then **no points will be awarded for the project**. 

  During the interview grading, TAs will be playing your game and asking
  questions about your game. They will also ask about your implementations
  and conceptual questions. 

- **Thursday, April 27<sup>th</sup>, 11:59 pm: Final Deliverables**.
  Your project will be due on **Thursday, April 27<sup>th</sup>, 11:59 pm**.
  You must submit a zip file to **Project 3** assignment on Canvas,
  including all `.h` and `.cpp` files. The submission should compile and run.
  TAs will also be grading comments and style. 

- **Friday, April 28<sup>th</sup>, 11:59 pm: Project Report**. 
  Write a 1-2 page report containing the following reflection questions: 

    - How did you prepare for the project? 
    - How did you develop our code skeleton? In what way(s) did you use your code skeleton? 
    - Reflect on how you could have done better or how you could have completed the project faster or more efficiently? 
    - In addition, write a paragraph answering the following question, in the context of the Project in CSCI 1300: Did you have any false starts, or begin down a path only to have to turn back when figuring out the strategy/algorithm for your Final Project program? Describe in detail what happened, for example, what specific decision led you to the false starts, or, if not, why do you think your work had progressed so smoothly. In either case, give a specific example. 

  The report should be a **1-inch margin, single space, 12pt font size,
  Times New Roman**. Submit a report as PDF to **Project3 Report** on Canvas. 
  **Every team member should submit an individual report, clearly distinct in content from their teammate.**


# Points Summary <a name="points"></a>
Project 3 is worth 150 points. Here is a summary of the points. 

| **Criteria**                                                      | Points |
| ----------------------------------------------------------------- | ----- |
| Code Skeleton                                                     | 10    |
| Project Report                                                    | 10    |
| Minimum Implementation Requirements                               | 30    |
| Game functionality                                                | 50    |
| Game Compilation, Algorithm, Comments, Style, Interview Questions | 50    |
| Recitation attendance (Weeks 13, 15, 16)*                         | -30   |
| Total                                                             | 150   |


**Note:** if your code does not compile, you cannot score above 50 points for the project.
