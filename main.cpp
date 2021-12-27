/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const std::string& l) : value(v), name(l)  {}  //1
    int value; //2
    std::string name; //3
};
struct Compare                                //4
{
    T* compare(T& a, T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr; 
    }
};

struct U
{
    float number1 { 0 }, number2 { 0 };
    float distanceShrinker(float& valueUpdated)      //12
    {
        std::cout << "U's number1 value: " << number1 << std::endl;
        number1 = valueUpdated;
        std::cout << "U's number1 updated value: " << number1 << std::endl;
        while( std::abs(number2 - number1) > 0.001f )
        {
            /*
            write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
            */
            number2 += 0.5f;
        }
        std::cout << "U's number2 updated value: " << number2 << std::endl;
        return number2 * number1;
    }
};

struct DistanceShrinker
{
    static float distanceShrinker(U& that, float& valueUpdated)        //10
    {
        std::cout << "U's number1 value: " << that.number1 << std::endl;
        that.number1 = valueUpdated;
        std::cout << "U's number1 updated value: " << that.number1 << std::endl;
        while( std::abs(that.number2 - that.number1) > 0.001f )
        {
            /*
             write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
            */
            that.number2 += .5f;
        }
        std::cout << "U's number2 updated value: " << that.number2 << std::endl;
        return that.number2 * that.number1;
    }
};        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T valchar1(5, "E");                                             //6
    T valchar2(6 , "M");                                             //6
    
    Compare f;                                            //7
    auto* smaller = f.compare(valchar1 ,valchar2);                              //8
    if (smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }
    else
    {
        std::cout << "a == b, please choose different values.." << std::endl;
    }

    U distance;
    float updatedValue = 5.f;
    std::cout << "[static func] distance shrinker's multiplied values: " << DistanceShrinker::distanceShrinker(distance,updatedValue) << std::endl;                  //11
    
    U memDistance;
    std::cout << "[member func] distance Shrinker's multiplied values: " << memDistance.distanceShrinker( updatedValue) << std::endl;
}
