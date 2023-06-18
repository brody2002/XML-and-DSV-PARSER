#include "DSVWriter.h"
#include <iostream>
#include "StringUtils.h"
#include "DataSink.h"
#include "StringDataSink.h"

struct CDSVWriter::SImplementation{
    std::shared_ptr<CDataSink> s;
    char d;
    bool q;
    bool WriteRow(const std::vector< std::string > &row);
};

CDSVWriter::CDSVWriter(std::shared_ptr< CDataSink > sink, char delimiter, bool quoteall) :
	DImplementation{std::make_unique<SImplementation>()}
{
	DImplementation->d = delimiter;
	DImplementation->q = quoteall;
	DImplementation->s = sink;
      // DImplementation->WriteRow(const std::vector< std::string > &row) = true;

}

// char GetDelimeter(){
//        return delimeter
// }


CDSVWriter::~CDSVWriter() = default;

bool CDSVWriter::SImplementation::WriteRow(const std::vector< std::string > &row){ 
      //CStringDataSink s;
      //CDataSink* s;
      //s = new CStringDataSink;
     // s->String().clear();
      std::vector<std::string> vector2 = row;
      int vect_size = vector2.size();
      const std::string d2(1, d);
      std::string vect_string = "";
       //std::cout<<"here"<<d<<endl;
//       for(int i = 0; i < vector2.size()-1; i++){
//               vect_string += vector2[i];
//               vect_string += d;
//       }
       vect_string = StringUtils::Join(d2, vector2);
       std::string temp_str;
      //std::cout<<"vect_String: "<<vect_string<<std::endl;
      for(int i =0; i < vect_size; i++){
              int finds = vect_string.find(d);
              temp_str = vector2[i];
              
       for(int j = 0; j < vector2[i].length(); j++){
              if(temp_str[j] == '\"' || isspace(temp_str[j])){
                     vector2[i].insert(j+1, 1, '\"');
                     //temp_str.insert(j, "\"");
                     //std::cout<<"here";
              }

       }
	 if(q == true){
		 vector2[i] = StringUtils::Center(vector2[i], vector2[i].length() + 2, '\"');
        }
         if(vector2[i].find(d) != -1){
              //std::cout<<"here"<<std::endl;
            std::string centered_string = StringUtils::Center(vector2[i], vector2[i].length() + 2, '\"');
             vector2[i] = centered_string;
	     continue;
         }
         
      }

       const std::string answer = StringUtils::Join(d2, vector2) + "\n";
 
       for(int i = 0; i < answer.length(); i++){
	       s->Put(answer[i]);
       }
      //std::cout<<"answer: "<<answer<<std::endl;
      //std::cout<<"str_func:"<<s->String()<<std::endl;
     //  if(s->String() == answer){
	       return true;
       //}
       //get string from the data sink class. if that is equal to answer then return true otherwise return false
       

       //return false;
}


bool CDSVWriter::WriteRow(const std::vector< std::string > &row){ 
       return DImplementation->WriteRow(row);
}