#include "StringUtils.h"

#include "iostream"

#include "iostream"

#include "iostream"

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    int str_to_include;//the second parameter of substr characters to count after starting index
    int length = str.length();
    std::string str2 = "";



    if(start > length)
        return 0;
    if(start < 0){
        start = str.length() + start;
        if(start < length && start < 0){
            
            // std::cout<<"start is now: "<< start<<std::endl;
            start = start % length;
            //accounts for negative indexes
            
        }
    }
    if(end == 0){
        str_to_include = start;
        start = end;
        str2 = str.substr(start, str_to_include);
        return str2;
        //acounts for no end paramater being given
        
        
    }
    
    if(end < 0 && end * -1 <= str.length()){
        end = length + end;
        // std::cout<<"end is: "<<end<<std::endl;
        if(end < length && end < 0){
            end = end % length;
            end = length + end;
        }
        //gives you the negative index of the end parameter
    }

    if(end < 0 && end * -1 > str.length()){
        std::string sad = "";
        return sad;
        //acounts for negative indexing not being infinite
        //it it's out of range it just returns an empty string
    }

    
    // std::cout<<"1: start is now at index: " <<start<<std::endl;
    // std::cout<<"2: end is now at index: " <<end<<std::endl;
    
    
    if(start - end > 0){
        return "";
        //accounts for when they are the same number
    }
    else{
        str_to_include = start - end;
        str_to_include = str_to_include * -1;
        // std::cout<<str_to_include<<std::endl;
        std::string str2 = str.substr(start, str_to_include);
        // std::cout<<"the sliced string is: "<<str2;
        return str2;
        //UTILIZES SUBSTRING FUNCTION IN #INCLUDE <STRING>
    }
    return str2;
}

std::string Capitalize(const std::string &str) noexcept{
    //check if string exists
    std::string str2 = str;
    std::string str3 = "";
    char FirstChr = str2[0];
    
    //check if not lowercase
    //or check if not a letter

    if(int(FirstChr) < 97 || int(FirstChr) > 122)
        return str2;

    else{
        std::string str3 = str2.substr(1);
        // at this point should only be 
        // "rody Roberts" if the given was "Brody Roberts"
        
        // make 'b' into 'B'
        //creates string "str3" into a string containing everything except the first character

        
        FirstChr = std::toupper(int(FirstChr));
        //learned about toupper from here https://cplusplus.com/reference/locale/toupper/
        
        // merge the two strings together
        
        std::string answer = "";
        answer = FirstChr+str3;
        //adds solo character and string together
        return answer;
    }
}

std::string Upper(const std::string &str) noexcept{
    int length = str.length();
    std::string str2 = str;
    for(int i = 0; i < length; i++){
        if(int(str2[i]) < 97 || int(str2[i]) > 122){
            // std::cout<<"this is lower case"<<std::endl;
            continue;
        }
        else{
            str2[i] = std::toupper(str2[i]);
        }
    }
    
    return str2;
    
}
    
    

std::string Lower(const std::string &str) noexcept{
    int length = str.length();
    std::string str2 = str;
    for(int i = 0; i < length; i++){
        if(int(str2[i]) < 65 || int(str2[i]) > 90){
            // std::cout<<"this is lower case"<<std::endl;
            continue;
        }
        else{
            str2[i] = std::tolower(str2[i]);
        }
    }
    
    return str2;
}

std::string LStrip(const std::string &str) noexcept{
    int counter = 0;
    for(int i = 0; i < str.length(); i++){
        // std::cout<<int(str[i])<<std::endl;
        if(int(str[i]) == 32 || int(str[i]) == 9 || int(str[i]) == 10|| int(str[i]) == 11||
        int(str[i]) == 12|| int(str[i]) == 13){
            counter = counter + 1;
            // std::cout<<counter<<std::endl;
        }
        else{
            // std::cout<<counter<<std::endl;
            // std::cout<<"line "<< i << " is "<<str[i]<<std::endl;
            // std::cout<<"this isn't a white space"<<std::endl;
            break;
        }
    }
    // std::cout<<"Amount of white charatcters deleated is: "<<counter<<std::endl;
    std::string str2 = str.substr(counter, str.length() - counter);
    // std::cout<<"The new string is now: "<<str2;

    //creates a substring starting from indexing after the whitespaces and then to the end of the 
    //original string: "  hello" --> "hello"
    return str2;
}

std::string RStrip(const std::string &str) noexcept{

   int counter = 0;
    for(int i = str.length() - 1; i >= 0; i--){
        // std::cout<<int(str[i])<<std::endl;
        if(int(str[i]) == 32 || int(str[i]) == 9 || int(str[i]) == 10|| int(str[i]) == 11||
        int(str[i]) == 12|| int(str[i]) == 13){
            counter = counter + 1;
            // std::cout<<counter<<std::endl;
        }
        else{
            // std::cout<<counter<<std::endl;
            // std::cout<<"line "<< i << " is "<<str[i]<<std::endl;
            // std::cout<<"this isn't a white space"<<std::endl;
            break;
        }
    }
    // std::cout<<"Amount of white charatcters deleated is: "<<counter<<std::endl;
    std::string str2 = str.substr(0, str.length() - counter);
    // std::cout<<"The new string is now: "<<str2;

    //creates a substring starting from 0 index then to the originial string length minus counter value
    //original string: "hello  " --> "hello"
    
    return str2;
}

std::string Strip(const std::string &str) noexcept{
    return RStrip(LStrip(str));
    //uses both functions
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    std::string str2 = str;
    int str_length = str.length();
    int right_length = (width - str_length) / 2; //floors this value
    int left_length = width - right_length - str_length; /*as a result the left will always have more spacers
    if value odd */
    std::string answer = "";
    
    
    // std::cout<<"string length is: "<<str_length<<std::endl;
    // std::cout<<"Lstring length is: "<<left_length<<std::endl;
    // std::cout<<"Rstring length is: "<<right_length<<std::endl;
    
    for(int i = 0; i < left_length; i++){
        answer.push_back(fill);
    }
    answer = answer + str;
    
    for(int i = 0; i < right_length; i++){
        answer.push_back(fill);
    }
    
    
    
    return answer;
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    int fill_length = width - str.length();
    std::string str2 = str;
    for(int i = 0; i < fill_length; i++){
        str2 = str2 + fill;
    }
    
    return str2;
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    std::string answer = "";
    for(int i =0; i < width - str.length(); i++){
        answer.push_back(fill);
    }
    answer = answer + str;
    return answer;
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    std::string str2 = str;
 
  int found = str2.find(old);
if(found == std::string::npos){
    // std::cout<<"end";
    return str;
  }
  //str.find returns string::npos if it doesn't find target soo.....
  //SOURCE: ^ https://cplusplus.com/reference/string/string/find/
  while(found != std::string::npos)
    {
      int start_index = str2.find(old);
    //finds index of first target string

    //   std::cout<<"starting index is: "<<start_index<<std::endl;
      std::string str3 = str2.substr(start_index, (str2.length () - str2.find (old)));
    //str3 becomes the subtring from index of target onwards

    //   std::cout<<"str3 is: "<<str3<<std::endl;
      str2.erase(start_index);
    //String the holds the deleated characters from str3

    //   std::cout<<"str2 is: "<<str2<<std::endl;
    //   std::cout<<"Slice returns: "<<Slice(str3, old.length(),str3.length())<<std::endl;
      str3 = StringUtils::Slice(str3, old.length(),str3.length());
    //SLICES THE FIRST TARGET WORD AWAY

    //   std::cout<<"str3 is: "<<str3<<std::endl;
      str2 = str2 +rep;

    //Adds the replacement word to str2


    //   std::cout<<"str2 is: "<<str2<<std::endl;
      str2 = str2 + str3;
    //creates new str2 to put into recursive loop

    //   std::cout << "Final string is: " << str2 << std::endl;
    //   std::cout<<"The leftover is: "<<str3<<std::endl;
    if(str3.find(old) == std::string::npos){
        // std::cout<<"FINAL: "<<str2<<std::endl;
        break;
        //break condition to stop recusion if it meets end of string
    }
    else{
        // std::cout<<"left over contain old word"<<std::endl;
        Replace(str2, old, rep);
        //runs it over again
    }
    }
    return str2;
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    std::vector<std::string> vect{};
    std::string str2 = str;
    int counter = 0;
    int index = 0;
    while((index = str2.find(splt)) != std::string::npos){
        // "A|B||C"
        
        if(index == 0 && counter == 0){
        str2 = str2.substr(1);
        counter++;
        continue;
        }
        vect.push_back(str2.substr(0, index));
        
        
        str2.erase(0, index + splt.length());
        if(str2.length() > 0 && str2.find(splt) == std::string::npos){
            vect.push_back(str2);
            str2.erase(0);
        }
        counter++;
    }

    
    return vect;
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    std::string str2 = str;
    std::string answer = "";
    int vect_size = vect.size();
    for(int i =0; i < vect_size; i++){


        answer = answer + vect[i];
        if(i != vect_size - 1){
            answer = answer + str2;
        }
        else{
            break;
        }

    }
    return answer;
}   

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    std::string str2= str;
    std::string back_half = "";
    std::string front_half = "";
    std::string tabcollecter = "";
    
    
    while(str2.find("\t") != std::string::npos){
        int index =str2.find("\t");
        // std::cout<<"str2 is at beggining of loop: "<<str2<<std::endl;
        // std::cout<<"hit at index: "<<index<<std::endl;
        
        front_half = str2.substr(0,index + 1);
        //Takes the one into string front half with tab character included

        // std::cout<<"front is: "<< front_half<<std::endl;
        front_half.erase(index);
        //the erases the tab character


        back_half = str2.substr(index + 1);
        //back half = rest of the original string


        // std::cout<<"back is: "<<back_half<<std::endl;
        int tabadder =  tabsize - (front_half.length() % tabsize);
        // std::cout<<"tabadder is: "<<tabadder<<std::endl;
        for(int i =0; i < tabadder; i++){
                
                tabcollecter = tabcollecter + " ";
            }
        //creates the amount of tabs needed for string, then adds them    
        str2 = front_half + tabcollecter;
        str2 = str2 + back_half;
        // std::cout<<"str2 is: "<<str2<<std::endl;
        tabcollecter = "";
        
        
    } 
    return str2;
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    
    std::string word1 = left;
    std::string word2 = right;
    int word1_length = word1.length() + 1;
    int word2_length = word2.length() + 1;
    int matrix[word1_length][word2_length];
    //^^^creates matrix with the dead characters in mind at [0,0] first 0 is collum and second is row
    for(int i = 0; i < word1_length; i++)/*loops through length first word i = collumns*/{
        for(int n = 0; n < word2_length; n++)/*loops through length of second word n = rows*/{
            if(i == 0){
                matrix[i][n] = n;
                // std::cout<<"matrix["<<i<<"]["<<n<<"] = "<< matrix[i][n]<<std::endl;
                //counts the 0-length of word
            }
            else if(n == 0){
                matrix[i][n] = i;
                // std::cout<<"matrix["<<i<<"]["<<n<<"] = "<< matrix[i][n]<<std::endl;
                //counts the 0-length of word
            }
            else{
                if(ignorecase == 0){
                    if(word2[n - 1] == word1[i - 1])
                    /*If the letter of word 2 is the same 
                    for letter of word 1 pass down the diagnal from top left*/
                    {
                    
                    // std::cout<<"word1[n-1] is: "<<word1[i - 1]<<std::endl;
                    // std::cout<<"word2[n-1] is: "<<word2[n - 1]<<std::endl;
                    matrix[i][n] = matrix[i-1][n-1];
                    // std::cout<<"matrix["<<i<<"]["<<n<<"] = "<< matrix[i][n]<<std::endl;
                    }
                    else{
                        /*take minimum of top, left, and diagnal left || then add 1*/
                        int x = std::min((matrix[i-1][n-1]),(matrix[i][n-1]));
                        x = std::min((matrix[i-1][n-1]),(matrix[i-1][n]));
                        matrix[i][n] = 1 + x;
                        // std::cout<<"matrix["<<i<<"]["<<n<<"] = "<< matrix[i][n]<<std::endl;
                    }
                    
                }
                else{
                    if( (int(word2[n - 1]) == int(word1[i - 1]) + 32) || (int(word2[n - 1]) == int(word1[i - 1]) - 32))
                    /*Check for capital and lower case being the same character...
                    If the letter of word 2 is the same 
                    for letter of word 1 pass down the diagnal from top left
                    TREATS LOWER AND UPPERCASE AS THE SAME!!!*/{
                    // std::cout<<"MATCH"<<std::endl;
                    // std::cout<<"word1 letter is: "<<word1[i - 1]<<std::endl;
                    // std::cout<<"word2 letter is: "<<word2[n - 1]<<std::endl;
                    matrix[i][n] = matrix[i-1][n-1];
                    // std::cout<<"matrix["<<i<<"]["<<n<<"] = "<< matrix[i][n]<<std::endl;
                    }
                    else{
                        /*take minimum of top, left, and diagnal left || then add 1*/
                        int x = std::min((matrix[i-1][n-1]),(matrix[i][n-1]));
                        x = std::min((matrix[i-1][n-1]),(matrix[i-1][n]));
                        matrix[i][n] = 1 + x;
                        // std::cout<<"matrix["<<i<<"]["<<n<<"] = "<< matrix[i][n]<<std::endl;
                    }
                }
                
            }
        }
    }
    
    return matrix[word1_length - 1][word2_length - 1];
}

}