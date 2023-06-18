#include "DSVReader.h"
#include <iostream>
#include "StringUtils.h"
#include "DataSource.h"
#include "StringDataSource.h"
#include "StringDataSink.h"

struct CDSVReader::SImplementation{
    std::shared_ptr<CDataSource> s;
    char d;
    bool End() const;
    bool ReadRow(std::vector<std::string> &row);
};

// Constructor for DSV reader, src specifies the data source and delimiter  
// specifies the delimiting character 
CDSVReader::CDSVReader(std::shared_ptr< CDataSource > src, char delimiter) :
    DImplementation{std::make_unique<SImplementation>()}
{
	DImplementation->s = src;
	DImplementation->d = delimiter;
}
 
// Destructor for DSV reader 
CDSVReader::~CDSVReader() = default;


// Returns true if all rows have been read from the DSV 
//bool End() const; 
//Call from the class in DSVReader.h
//Figure out the file to initial the src and delimiter characters
//

/*Bool CDSVReader::ReadRow(vect, &row_number){
    maybe a for loop to iterate through the first line of a file...
    And make a string for every character
    
    str2 = str2 + chr;
    return true;

    check if the read string in the function matches a test case
    
} */

bool CDSVReader::SImplementation::ReadRow(std::vector<std::string> &row){
    row.clear();
    const std::string delimeter = ",";
    std::string str;
    char ch;
    while(!s->End()){
        s->Get(ch);
        
        str += ch;
    }
    const std::string strcopy = str;
    std::string strcopy2;
    const std::string newline = "\n";
    strcopy2 = StringUtils::Replace(strcopy, newline, delimeter);
    row = StringUtils::Split(strcopy2, delimeter);
    return true;
   
}
bool CDSVReader::ReadRow(std::vector< std::string > &row){ 
       return DImplementation->ReadRow(row);
}

bool CDSVReader::SImplementation::End() const{
    return s->End();
}
bool CDSVReader::End() const{
    
    return DImplementation->End();
}


/*Things to look for in function:
    String ----> Vector
    
    Number of Quotations: if number is of quotations exceeds 2 before a delimiter character (quotation characters) then acknowldege that quotation is in String
    
    Comma Case: if delimiter occurs before a second quotation mark then make note that delimiter is in the String
    
    Otherwise, 
    1: StringUtils::Slice from beggining of originial string to ending delimiter character and make new string
    2: take out quotaions on the outside of the function. Make note if quotation counter is 4 or larger. 
    3: Add remainder of string to a vector 
    
    NOTE: THIS VERSION DOESN'T READ A SPECIFIC LINE OF THE FILE! BOOLEAN TYPE AND ROW VALUE WERE TAKEN OUT OF THE FUNCTION!!!
    
    

//--------------------------------------------------
 
// Returns true if the row is successfully read, one string will be put in  
// the row per column 
bool ReadRow(std::vector< std::string > &row); 

//i think we call ReadRow from DSVReader.h
//so something like this... 
*/