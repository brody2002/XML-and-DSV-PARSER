#include <gtest/gtest.h>
#include "DSVReader.h"
#include "DSVWriter.h"
#include "DataSink.h"
#include "StringDataSink.h"
#include "StringDataSource.h"
#include <iostream>

//in the makefil when you start the xml -- make sure to include -xpat wit the ldflags
//the rest of the makefile is the same copied, jsut change the names you stupid fuck
TEST(DSVTest, WriteRow){

	
	
	// //sink = std::make_shared <CDataSink
	// auto sink = std::make_shared <CStringDataSink>();
	// CDSVWriter writer(sink, ',', false);


	// // // writer.sink = sink;
	// // // writer.delimiter = ',';
	// // // writer.quoteall = false;

	
	// // // delimiter = ","
	// std::string checker = "literally,anything,bro\n";
 	// std::vector<std::string> vector{"literally", "anything", "bro"};
	// EXPECT_EQ(true, writer.WriteRow(vector));
	// EXPECT_EQ(checker, sink->String());

	// checker = "literally,anything,bro\nliterally\n";	
	// vector = {"literally"};
	// EXPECT_EQ(true, writer.WriteRow(vector));
	// EXPECT_EQ(checker, sink->String());

	// checker = "literally,anything,bro\nliterally\n\n";	
 	// vector = {""};
	// EXPECT_EQ(true, writer.WriteRow(vector));//is this supposed to return false 
	// EXPECT_EQ(checker, sink->String());

	// checker = "literally,anything,bro\nliterally\n\n\",\"\n";	
	// vector = {","};
	// EXPECT_EQ(true, writer.WriteRow(vector));
	// EXPECT_EQ(checker, sink->String());

	// checker = "literally,anything,bro\nliterally\n\n\",\"\nhello,\",,I\",\"am,,\",\",,\",\"s,,tu,pid,\"\n";	
	// vector = {"hello", ",,I", "am,,", ",,", "s,,tu,pid,"};
	// EXPECT_EQ(true, writer.WriteRow(vector));
	// EXPECT_EQ(checker, sink->String());

 	// checker = "literally,anything,bro\nliterally\n\n\",\"\nhello,\",,I\",\"am,,\",\",,\",\"s,,tu,pid,\"\n\"\",\",\",\n";	
	// vector = {"\"", ",", ""};
	// EXPECT_EQ(true, writer.WriteRow(vector));
	// EXPECT_EQ(checker, sink->String());
	
 	// checker = "literally,anything,bro\nliterally\n\n\",\"\nhello,\",,I\",\"am,,\",\",,\",\"s,,tu,pid,\"\n\"\",\",\",\n\",\",\",\"\n";
	// vector = {",", ","};
	// EXPECT_EQ(true, writer.WriteRow(vector));
	// EXPECT_EQ(checker, sink->String());
 	
	// checker = "literally,anything,bro\nliterally\n\n\",\"\nhello,\",,I\",\"am,,\",\",,\",\"s,,tu,pid,\"\n\"\",\",\",\n\",\",\",\"\n,hello,\n";
	// vector = {"", "hello", ""};
	// EXPECT_EQ(true, writer.WriteRow(vector));
	// EXPECT_EQ(checker, sink->String());

	// checker = "literally,anything,bro\nliterally\n\n\",\"\nhello,\",,I\",\"am,,\",\",,\",\"s,,tu,pid,\"\n\"\",\",\",\n\",\",\",\"\n,hello,\n\"abc\",\"abc\"\n";
	// CDSVWriter writer2(sink, ',', true);
	// vector = {"abc", "abc"};
	// EXPECT_EQ(true, writer2.WriteRow(vector));
	// EXPECT_EQ(checker, sink->String());

	// checker = "literally,anything,bro\nliterally\n\n\",\"\nhello,\",,I\",\"am,,\",\",,\",\"s,,tu,pid,\"\n\"\",\",\",\n\",\",\",\"\n,hello,\n\"abc\",\"abc\"\n\"\"hello,,there\"\",\"\",abc,\"\",\"\"\n";
	// vector = {"hello,,there", ",abc,", ""};
	// EXPECT_EQ(true, writer2.WriteRow(vector));
	// EXPECT_EQ(checker, sink->String());
}

TEST(DSVTest, ReadRow){
	
	// //sink = std::make_shared <CDataSink
	// auto source = std::make_shared <CStringDataSource>("hello,woorld");/*string*/
	// CDSVReader reader(source, ',');
	// std::vector <std::string> str;
	// std::vector <std::string> vect{};
	// /*vectoor*/str = {"hello","woorld"};
	// EXPECT_EQ(true, reader.ReadRow(vect));
	// EXPECT_EQ(vect, str);
	// //TESTED
/*
	
	source = std::make_shared <CStringDataSource>("");
	CDSVReader reader3(source, ',');
 	str = {""};
	EXPECT_EQ(true, reader3.ReadRow(vect));//is this supposed to return false 
	EXPECT_EQ(vect, str);
	
	source = std::make_shared <CStringDataSource>(",");
	CDSVReader reader4(source, ',');
	str = {"",""};
	EXPECT_EQ(true, reader4.ReadRow(vect));
	EXPECT_EQ(vect, str);

	
	source = std::make_shared <CStringDataSource>("\",\",\",\"");
	CDSVReader reader5(source, ',');
 	str = {",", ","};
	EXPECT_EQ(true, reader5.ReadRow(vect));
	EXPECT_EQ(vect, str);
	*/
 	
	// source = std::make_shared <CStringDataSource>("\",hello,\"");
	// CDSVReader reader2(source, ',');
	// str = {"", "hello", ""};
	// EXPECT_EQ(true, reader2.ReadRow(vect));
	// EXPECT_EQ(vect, str);

	// CDSVWriter writer2(source, ',', true);
	// str = {"abc", "abc"};
	// EXPECT_EQ(true, writer2.WriteRow(vect));

	// str = {"hello,,there", ",abc,", ""};
	// EXPECT_EQ(true, writer2.WriteRow(vect));

	// // //delimeter = ""
	// CDSVWriter writer3(sink, '\t', true);
	
	// str = {"\t", " ", "\""};
	// EXPECT_EQ(true, writer3.WriteRow(vect));

	// CDSVWriter writer4(sink, '\"', true);
	
	// str = {"	", "/t", "\""};
	// EXPECT_EQ(true, writer4.WriteRow(vect));
}