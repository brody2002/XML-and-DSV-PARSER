#include "XMLReader.h"
#include <expat.h>
#include <deque>
#include <iostream>
#include "StringUtils.h"

struct CXMLReader::SImplementation{
    std::shared_ptr< CDataSource > DSource;
    XML_Parser DParser;
    std::deque<SXMLEntity> DEntities;

    void StartElement(const XML_Char *name, const XML_Char **atts){
      
        SXMLEntity NewEntity;
        size_t Index = 0;
        NewEntity.DNameData = name;
        while(atts[Index]){
            NewEntity.SetAttribute(atts[Index],atts[Index+1]);
            Index += 2;
        }
        NewEntity.DType = SXMLEntity::EType::StartElement;
        DEntities.push_back(NewEntity);
        
    };

    void EndElement(const XML_Char *name){
        SXMLEntity NewEntity;
        NewEntity.DNameData = name;
        //std::cout<<"ENdname"<<NewEntity.DNameData<<std::endl;
        NewEntity.DType = SXMLEntity::EType::EndElement;
        DEntities.push_back(NewEntity);
    };

    void CharacterData(const XML_Char *s, int len){
        SXMLEntity NewEntity;
        NewEntity.DNameData = s;
        NewEntity.DType = SXMLEntity::EType::CharData;
        DEntities.push_back(NewEntity);
        len = NewEntity.DNameData.length();
    };

    static void StartElementCallback(void *userData, const XML_Char *name, const XML_Char **atts){
        SImplementation *ReaderImplementation = (SImplementation *)userData;
        ReaderImplementation->StartElement(name,atts);
    };

    static void EndElementCallback(void *userData, const XML_Char *name){
        SImplementation *ReaderImplementation = (SImplementation *)userData;
        ReaderImplementation->EndElement(name);
    };

    static void CharacterDataCallback(void *userData, const XML_Char *s, int len){
        SImplementation *ReaderImplementation = (SImplementation *)userData;
        ReaderImplementation->CharacterData(s,len);
    };

    SImplementation(std::shared_ptr< CDataSource > src){
        DSource = src;
        DParser = XML_ParserCreate(NULL);
        XML_SetUserData(DParser,this);
        XML_SetElementHandler(DParser,StartElementCallback,EndElementCallback);
        XML_SetCharacterDataHandler(DParser,CharacterDataCallback);
    };

    ~SImplementation(){
        XML_ParserFree(DParser);
    }

    bool End() const{
        return true;
    };
   
    bool ReadEntity(SXMLEntity &entity, bool skipcdata){
        //entity.DAttributes.clear();
        bool Done = false;

        while(!Done){
            std::vector<char> Buffer;
            if(DSource->Read(Buffer, 128)){
                XML_Parse(DParser,Buffer.data(),Buffer.size(),DSource->End());
            }
            if(!DEntities.empty()){
                entity = DEntities.front();
                if(skipcdata ==true && entity.DType == SXMLEntity::EType::CharData ){
                    DEntities.pop_front(); 
                    entity = DEntities.front();
                }
                DEntities.pop_front(); 
                
               
        }
    break;
        }
        //DEntities.clear();
        return true;
    };
};
        
CXMLReader::CXMLReader(std::shared_ptr< CDataSource > src){
    DImplementation = std::make_unique<SImplementation>(src);
}

CXMLReader::~CXMLReader() = default;

bool CXMLReader::End() const{
    return DImplementation->End();
}

bool CXMLReader::ReadEntity(SXMLEntity &entity, bool skipcdata){
    return DImplementation->ReadEntity(entity,skipcdata);
}