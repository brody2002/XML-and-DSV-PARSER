#include <gtest/gtest.h>
#include "XMLReader.h"
#include "XMLWriter.h"
#include "StringUtils.h"
#include "StringDataSource.h"
#include "StringDataSink.h"

TEST(XMLReaderTest, SimpleTest){
    auto InStream = std::make_shared<CStringDataSource>("<element name=\"val\"></element>");
    CXMLReader Reader(InStream);
    SXMLEntity Entity;
    
    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::StartElement);
    EXPECT_EQ(Entity.DNameData, "element");
    EXPECT_EQ(Entity.DAttributes.size(), 1);
    EXPECT_TRUE(Entity.AttributeExists("name"));
    EXPECT_EQ(Entity.AttributeValue("name"), "val");
    
    EXPECT_TRUE(Reader.ReadEntity(Entity));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::EndElement);
    EXPECT_EQ(Entity.DNameData, "element");
    EXPECT_EQ(Entity.DAttributes.size(), 0);
    
}

TEST(XMLReaderTest, ElementTest){
    auto InStream = std::make_shared<CStringDataSource>("<?xml version='1.0' encoding='UTF-8'?>\n"
                                                        "<osm version=\"0.6\" generator=\"osmconvert 0.8.5\">\n"
                                                        "<node id=\"62208369\" lat=\"38.5178523\" lon=\"-121.7712408\"/>\n"
                                                        "<node id=\"62209104\" lat=\"38.535052\" lon=\"-121.7408606\"/>\n"
                                                        "</osm>");
    CXMLReader Reader(InStream);
    SXMLEntity Entity;
    
   
    EXPECT_TRUE(Reader.ReadEntity(Entity, true));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::StartElement);
    EXPECT_EQ(Entity.DNameData, "osm");
    EXPECT_EQ(Entity.DAttributes.size(), 2);
    if(Entity.DAttributes.size() == 2){
        EXPECT_TRUE(Entity.AttributeExists("version"));
        EXPECT_EQ(Entity.AttributeValue("version"), "0.6");
        EXPECT_TRUE(Entity.AttributeExists("generator"));
        EXPECT_EQ(Entity.AttributeValue("generator"), "osmconvert 0.8.5");
    }
    
    EXPECT_TRUE(Reader.ReadEntity(Entity, true));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::StartElement);
    EXPECT_EQ(Entity.DNameData, "node");
    EXPECT_EQ(Entity.DAttributes.size(), 3);
    if(Entity.DAttributes.size() == 3){
        EXPECT_TRUE(Entity.AttributeExists("id"));
        EXPECT_EQ(Entity.AttributeValue("id"), "62208369");
        EXPECT_TRUE(Entity.AttributeExists("lat"));
        EXPECT_EQ(Entity.AttributeValue("lat"), "38.5178523");
        EXPECT_TRUE(Entity.AttributeExists("lon"));
        EXPECT_EQ(Entity.AttributeValue("lon"), "-121.7712408");
    }
    
    EXPECT_TRUE(Reader.ReadEntity(Entity, true));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::EndElement);
    EXPECT_EQ(Entity.DNameData, "node");
    EXPECT_EQ(Entity.DAttributes.size(), 0);
    
    
    EXPECT_TRUE(Reader.ReadEntity(Entity, true));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::StartElement);
    EXPECT_EQ(Entity.DNameData, "node");
    EXPECT_EQ(Entity.DAttributes.size(), 3);
    if(Entity.DAttributes.size() == 3){
        EXPECT_TRUE(Entity.AttributeExists("id"));
        EXPECT_EQ(Entity.AttributeValue("id"), "62209104");
        EXPECT_TRUE(Entity.AttributeExists("lat"));
        EXPECT_EQ(Entity.AttributeValue("lat"), "38.535052");
        EXPECT_TRUE(Entity.AttributeExists("lon"));
        EXPECT_EQ(Entity.AttributeValue("lon"), "-121.7408606");
    }
    
    EXPECT_TRUE(Reader.ReadEntity(Entity, true));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::EndElement);
    EXPECT_EQ(Entity.DNameData, "node");
    EXPECT_EQ(Entity.DAttributes.size(), 0);

    EXPECT_TRUE(Reader.ReadEntity(Entity, true));
    EXPECT_EQ(Entity.DType, SXMLEntity::EType::EndElement);
    EXPECT_EQ(Entity.DNameData, "osm");
    EXPECT_EQ(Entity.DAttributes.size(), 0);
    
    EXPECT_TRUE(Reader.End());
}