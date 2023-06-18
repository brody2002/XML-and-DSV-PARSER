#include <gtest/gtest.h>
#include "DSVReader.h"
#include "DSVWriter.h"
#include "DataSink.h"
#include "StringDataSink.h"
#include "StringDataSource.h"
#include "BusSystem.h"
#include "CSVBusSystem.h"
#include <iostream>


TEST(CSVBusSystem, ComparePointers){

//stops
auto routesrc = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033\nA,22076");/*string*/
auto stopsrc = std::make_shared <CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479\n22079,2580285987");/*string*/
auto CSVRStops = std::make_shared<CDSVReader>(stopsrc,',');
auto CSVRRoutes = std::make_shared<CDSVReader>(routesrc,',');
CCSVBusSystem bus(CSVRStops, CSVRRoutes);
EXPECT_EQ(bus.StopByID(22043), bus.StopByIndex(0));

//routes

EXPECT_EQ(bus.RouteByName("A"), bus.RouteByIndex(0));

}

TEST(CSVBusSystem, StopCount){
// Returns the number of stops in the system 

//when it's 9
//std::cout<<"TEST1"<<std::endl;
auto routesrc = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033\nA,22076");/*string*/
auto stopsrc = std::make_shared <CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479\n22079,2580285987");/*string*/
auto CSVRStops = std::make_shared<CDSVReader>(stopsrc,',');
auto CSVRRoutes = std::make_shared<CDSVReader>(routesrc,',');
CCSVBusSystem bus(CSVRStops, CSVRRoutes);
EXPECT_EQ(9, bus.StopCount());

//when its 1
// std::cout<<"TEST2"<<std::endl;
auto routesrc2 = std::make_shared <CStringDataSource>("route,stop_id\nA,22258");/*string*/
auto stopsrc2 = std::make_shared <CStringDataSource>("stop_id,node_id\n22043,2849810514");/*string*/
auto CSVRStops2 = std::make_shared<CDSVReader>(stopsrc2,',');
auto CSVRRoutes2 = std::make_shared<CDSVReader>(routesrc2,',');
CCSVBusSystem bus2(CSVRStops2, CSVRRoutes2);
EXPECT_EQ(1, bus2.StopCount());

//when its 0
// std::cout<<"TEST3"<<std::endl;
auto routesrc3 = std::make_shared <CStringDataSource>("route,stop_id");/*string*/
auto stopsrc3 = std::make_shared <CStringDataSource>("stop_id,node_id");/*string*/
auto CSVRStops3 = std::make_shared<CDSVReader>(stopsrc3,',');
auto CSVRRoutes3 = std::make_shared<CDSVReader>(routesrc3,',');
CCSVBusSystem bus3(CSVRStops3, CSVRRoutes3);
EXPECT_EQ(0, bus3.StopCount());

//when its emptystring
// std::cout<<"TEST4"<<std::endl;
auto routesrc4 = std::make_shared <CStringDataSource>("route,stop_id");/*string*/
auto stopsrc4 = std::make_shared <CStringDataSource>("");/*string*/
auto CSVRStops4 = std::make_shared<CDSVReader>(stopsrc4,',');
auto CSVRRoutes4 = std::make_shared<CDSVReader>(routesrc4,',');
CCSVBusSystem bus4(CSVRStops4, CSVRRoutes4);
EXPECT_EQ(0, bus4.StopCount());


}


// Returns the number of routes in the system 
TEST(CSVBusSystem, RouteCount){

//when route count is 1
auto routesrc = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033");/*string*/
auto stopsrc = std::make_shared<CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops = std::make_shared<CDSVReader>(stopsrc,',');
auto CSVRRoutes = std::make_shared<CDSVReader>(routesrc,',');
CCSVBusSystem bus(CSVRStops, CSVRRoutes);
EXPECT_EQ(1, bus.RouteCount());

//when route count is 0
auto routesrc2 = std::make_shared <CStringDataSource>("route,stop_id");/*string*/
auto stopsrc2 = std::make_shared <CStringDataSource>("stop_id,node_id");/*string*/
auto CSVRStops2 = std::make_shared<CDSVReader>(stopsrc2,',');
auto CSVRRoutes2 = std::make_shared<CDSVReader>(routesrc2,',');
CCSVBusSystem bus2(CSVRStops2, CSVRRoutes2);
EXPECT_EQ(0, bus2.RouteCount());

//when route is empty string
auto routesrc7 = std::make_shared <CStringDataSource>("");/*string*/
auto stopsrc7 = std::make_shared <CStringDataSource>("stop_id,node_id");/*string*/
auto CSVRStops7 = std::make_shared<CDSVReader>(stopsrc7,',');
auto CSVRRoutes7 = std::make_shared<CDSVReader>(routesrc7,',');
CCSVBusSystem bus7(CSVRStops7, CSVRRoutes7);
EXPECT_EQ(0, bus7.RouteCount());

//when route count is 3
auto routesrc3 = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033\nB,22022\nXZ,2022");/*string*/
auto stopsrc3 = std::make_shared <CStringDataSource>("stop_id,node_id");/*string*/
auto CSVRStops3 = std::make_shared<CDSVReader>(stopsrc3,',');
auto CSVRRoutes3 = std::make_shared<CDSVReader>(routesrc3,',');
CCSVBusSystem bus3(CSVRStops3, CSVRRoutes3);
EXPECT_EQ(3, bus3.RouteCount());

}

//EXPECT_EQ(BusSystem.StopByIndex(0)->ID(),1);
TEST(CSVBusSystem, StopByIndex){
// Returns the SStop specified by the index, nullptr is returned if index is 
// greater than equal to StopCount()   
// std::cout<<"TEST1"<<std::endl;  

//index is 3
auto routesrc = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033");/*string*/
auto stopsrc = std::make_shared<CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops = std::make_shared<CDSVReader>(stopsrc,',');
auto CSVRRoutes = std::make_shared<CDSVReader>(routesrc,',');
CCSVBusSystem bus(CSVRStops, CSVRRoutes);
EXPECT_EQ(22175, bus.StopByIndex(3)->ID());

// index is greater than number of stops
auto routesrc2 = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033");/*string*/
auto stopsrc2 = std::make_shared <CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops2 = std::make_shared<CDSVReader>(stopsrc2,',');
auto CSVRRoutes2 = std::make_shared<CDSVReader>(routesrc2,',');
CCSVBusSystem bus2(CSVRStops2, CSVRRoutes2);
EXPECT_EQ(nullptr, bus2.StopByIndex(11));

//index is less than 0
auto routesrc3 = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033");/*string*/
auto stopsrc3 = std::make_shared <CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops3 = std::make_shared<CDSVReader>(stopsrc3,',');
auto CSVRRoutes3 = std::make_shared<CDSVReader>(routesrc3,',');
CCSVBusSystem bus3(CSVRStops3, CSVRRoutes3);
EXPECT_EQ(nullptr, bus3.StopByIndex(-2));

//index is the first element
auto routesrc4 = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033");/*string*/
auto stopsrc4 = std::make_shared <CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops4 = std::make_shared<CDSVReader>(stopsrc4,',');
auto CSVRRoutes4 = std::make_shared<CDSVReader>(routesrc4,',');
CCSVBusSystem bus4(CSVRStops4, CSVRRoutes4);
EXPECT_EQ(22043, bus4.StopByIndex(0)->ID());

//index is equal to the size
auto routesrc5 = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033");/*string*/
auto stopsrc5 = std::make_shared <CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops5 = std::make_shared<CDSVReader>(stopsrc5,',');
auto CSVRRoutes5 = std::make_shared<CDSVReader>(routesrc5,',');
CCSVBusSystem bus5(CSVRStops5, CSVRRoutes5);
EXPECT_EQ(nullptr, bus5.StopByIndex(8));

//index is the last element
EXPECT_EQ(22078, bus5.StopByIndex(7)->ID());


}


TEST(CSVBusSystem, StopByID){
// Returns the SStop specified by the stop id, nullptr is returned if id is 
// not in the stops 

//id of a stop in the list
auto routesrc = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033");/*string*/
auto stopsrc = std::make_shared<CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,33333\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops = std::make_shared<CDSVReader>(stopsrc,',');
auto CSVRRoutes = std::make_shared<CDSVReader>(routesrc,',');
CCSVBusSystem bus(CSVRStops, CSVRRoutes);
EXPECT_EQ(33333, bus.StopByID(22105)->NodeID());
//first element
EXPECT_EQ(2849810514, bus.StopByID(22043)->NodeID());
//last element
EXPECT_EQ(1190339479, bus.StopByID(22078)->NodeID());


//id doesnt exist
auto routesrc2 = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033");/*string*/
auto stopsrc2 = std::make_shared <CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops2 = std::make_shared<CDSVReader>(stopsrc2,',');
auto CSVRRoutes2 = std::make_shared<CDSVReader>(routesrc2,',');
CCSVBusSystem bus2(CSVRStops2, CSVRRoutes2);
EXPECT_EQ(nullptr, bus2.StopByID(987654321));

//id is a negative nuumber
auto routesrc3 = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033");/*string*/
auto stopsrc3 = std::make_shared <CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops3 = std::make_shared<CDSVReader>(stopsrc3,',');
auto CSVRRoutes3 = std::make_shared<CDSVReader>(routesrc3,',');
CCSVBusSystem bus3(CSVRStops3, CSVRRoutes3);
EXPECT_EQ(nullptr, bus3.StopByID(-1));
    
}


TEST(CSVBusSystem, RouteByIndex){
// Returns the SRoute specified by the index, nullptr is returned if index is 
// greater than equal to RouteCount() 

//last index
auto routesrc = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033");/*string*/
auto stopsrc = std::make_shared<CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops = std::make_shared<CDSVReader>(stopsrc,',');
auto CSVRRoutes = std::make_shared<CDSVReader>(routesrc,',');
CCSVBusSystem bus(CSVRStops, CSVRRoutes);
EXPECT_EQ(22033, bus.RouteByIndex(7)->GetStopID(7));


// std::cout<<"TEST2"<<std::endl;
//index is greater than amount of indexes
auto routesrc2 = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033");/*string*/
auto stopsrc2 = std::make_shared <CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops2 = std::make_shared<CDSVReader>(stopsrc2,',');
auto CSVRRoutes2 = std::make_shared<CDSVReader>(routesrc2,',');
CCSVBusSystem bus2(CSVRStops2, CSVRRoutes2);
EXPECT_EQ(nullptr, bus2.RouteByIndex(11));


// std::cout<<"TEST3"<<std::endl;
//index is less than 0
auto routesrc3 = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033");/*string*/
auto stopsrc3 = std::make_shared <CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops3 = std::make_shared<CDSVReader>(stopsrc3,',');
auto CSVRRoutes3 = std::make_shared<CDSVReader>(routesrc3,',');
CCSVBusSystem bus3(CSVRStops3, CSVRRoutes3);
EXPECT_EQ(nullptr, bus3.RouteByIndex(-2)); 
// std::cout<<"TEST4"<<std::endl;

//index is the number of indexes 
auto routesrc4 = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033\nK,1234");/*string*/
auto stopsrc4 = std::make_shared <CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops4 = std::make_shared<CDSVReader>(stopsrc4,',');
auto CSVRRoutes4 = std::make_shared<CDSVReader>(routesrc4,',');
CCSVBusSystem bus4(CSVRStops4, CSVRRoutes4);
EXPECT_EQ(1234, bus4.RouteByIndex(8)->GetStopID(8)); 

//fist element
EXPECT_EQ(22258, bus4.RouteByIndex(0)->GetStopID(0)); 



}



TEST(CSVBusSystem, RouteByName){
// Returns the SRoute specified by the name, nullptr is returned if name is 
// not in the routes 


auto routesrc = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033");/*string*/
auto stopsrc = std::make_shared<CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops = std::make_shared<CDSVReader>(stopsrc,',');
auto CSVRRoutes = std::make_shared<CDSVReader>(routesrc,',');
CCSVBusSystem bus(CSVRStops, CSVRRoutes);
EXPECT_EQ(22169, bus.RouteByName("A")->GetStopID(1));

auto routesrc2 = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033");/*string*/
auto stopsrc2 = std::make_shared <CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops2 = std::make_shared<CDSVReader>(stopsrc2,',');
auto CSVRRoutes2 = std::make_shared<CDSVReader>(routesrc2,',');
CCSVBusSystem bus2(CSVRStops, CSVRRoutes);
EXPECT_EQ(nullptr, bus2.RouteByName("NOT_THERE"));

auto routesrc3 = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033\nK,2022");/*string*/
auto stopsrc3 = std::make_shared <CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops3 = std::make_shared<CDSVReader>(stopsrc3,',');
auto CSVRRoutes3 = std::make_shared<CDSVReader>(routesrc3,',');
CCSVBusSystem bus3(CSVRStops3, CSVRRoutes3);
EXPECT_EQ(2022, bus3.RouteByName("K")->GetStopID(8));  

auto routesrc4 = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033\nK,2022");/*string*/
auto stopsrc4 = std::make_shared <CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops4 = std::make_shared<CDSVReader>(stopsrc4,',');
auto CSVRRoutes4 = std::make_shared<CDSVReader>(routesrc4,',');
CCSVBusSystem bus4(CSVRStops4, CSVRRoutes4);
EXPECT_EQ(8, bus4.RouteByName("A")->StopCount()); 
//^^^ following line tests GetStopID

auto routesrc5 = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033\nK,2022");/*string*/
auto stopsrc5 = std::make_shared <CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops5 = std::make_shared<CDSVReader>(stopsrc5,',');
auto CSVRRoutes5 = std::make_shared<CDSVReader>(routesrc5,',');
CCSVBusSystem bus5(CSVRStops5, CSVRRoutes5);
EXPECT_EQ(nullptr, bus5.RouteByName("")); 
}





TEST(CSVBusSystem, ID){
// Bus System Stop member functions 
// Returns the stop id of the stop   
//PIAZZA?????????????????? when would the ID member function call be NULL?? or not work what's an edge???
auto routesrc = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033");/*string*/
auto stopsrc = std::make_shared<CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops = std::make_shared<CDSVReader>(stopsrc,',');
auto CSVRRoutes = std::make_shared<CDSVReader>(routesrc,',');
CCSVBusSystem bus(CSVRStops, CSVRRoutes);
EXPECT_EQ(22043, bus.StopByIndex(0)->ID());

auto routesrc2 = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033");/*string*/
auto stopsrc2 = std::make_shared<CStringDataSource>("stop_id,node_id\n0,2849810514\n11,2849805223\n22,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops2 = std::make_shared<CDSVReader>(stopsrc2,',');
auto CSVRRoutes2 = std::make_shared<CDSVReader>(routesrc2,',');
CCSVBusSystem bus2(CSVRStops2, CSVRRoutes2);
EXPECT_EQ(22, bus2.StopByIndex(2)->ID());
}




TEST(CSVBusSystem, NodeID){
// Returns the node id of the bus stop

// std::cout<<"test 1"<<std::endl;
auto routesrc = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033");/*string*/
auto stopsrc = std::make_shared<CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,711\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops = std::make_shared<CDSVReader>(stopsrc,',');
auto CSVRRoutes = std::make_shared<CDSVReader>(routesrc,',');
CCSVBusSystem bus(CSVRStops, CSVRRoutes);
EXPECT_EQ(711, bus.StopByIndex(2)->NodeID());
// std::cout<<"test 2"<<std::endl;
auto routesrc2 = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033");/*string*/
auto stopsrc2 = std::make_shared<CStringDataSource>("stop_id,node_id\n33,999\n22358,2849805223\n22105,3954294407\n711,711\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops2 = std::make_shared<CDSVReader>(stopsrc2,',');
auto CSVRRoutes2 = std::make_shared<CDSVReader>(routesrc2,',');
CCSVBusSystem bus2(CSVRStops2, CSVRRoutes2);
EXPECT_EQ(711, bus2.StopByID(711)->NodeID());

}





TEST(CSVBusSystem, Name){
// Bus System Route member functions 
// Returns the name of the route
auto routesrc = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033\nK,2022");/*string*/
auto stopsrc = std::make_shared<CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops = std::make_shared<CDSVReader>(stopsrc,',');
auto CSVRRoutes = std::make_shared<CDSVReader>(routesrc,',');
CCSVBusSystem bus(CSVRStops, CSVRRoutes);
EXPECT_EQ("A", bus.RouteByIndex(3)->Name());

auto routesrc2 = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033\nK,2022");/*string*/
auto stopsrc2 = std::make_shared<CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops2 = std::make_shared<CDSVReader>(stopsrc2,',');
auto CSVRRoutes2 = std::make_shared<CDSVReader>(routesrc2,',');
CCSVBusSystem bus2(CSVRStops2, CSVRRoutes2);
EXPECT_EQ("A", bus2.RouteByName("A")->Name()); 

}





TEST(CSVBusSystem, GetStopID){
// Returns the stop id specified by the index, returns InvalidStopID if index 
// is greater than or equal to StopCount() 
auto routesrc = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033\nK,2022");/*string*/
auto stopsrc = std::make_shared<CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops = std::make_shared<CDSVReader>(stopsrc,',');
auto CSVRRoutes = std::make_shared<CDSVReader>(routesrc,',');
CCSVBusSystem bus(CSVRStops, CSVRRoutes);
EXPECT_EQ(22005, bus.RouteByIndex(3)->GetStopID(3));


auto routesrc2 = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033\nK,2022");/*string*/
auto stopsrc2 = std::make_shared<CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops2 = std::make_shared<CDSVReader>(stopsrc2,',');
auto CSVRRoutes2 = std::make_shared<CDSVReader>(routesrc2,',');
CCSVBusSystem bus2(CSVRStops2, CSVRRoutes2);
EXPECT_EQ(int(CStreetMap::InvalidNodeID), bus2.RouteByName("A")->GetStopID(100));

auto routesrc3 = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033\nK,2022");/*string*/
auto stopsrc3 = std::make_shared<CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops3 = std::make_shared<CDSVReader>(stopsrc3,',');
auto CSVRRoutes3 = std::make_shared<CDSVReader>(routesrc3,',');
CCSVBusSystem bus3(CSVRStops3, CSVRRoutes3);
EXPECT_EQ(22258, bus3.RouteByIndex(0)->GetStopID(0));

EXPECT_EQ(2022, bus3.RouteByIndex(8)->GetStopID(8));


auto routesrc4 = std::make_shared <CStringDataSource>("route,stop_id\nA,22258\nA,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033\nK,2022");/*string*/
auto stopsrc4 = std::make_shared<CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops4 = std::make_shared<CDSVReader>(stopsrc4,',');
auto CSVRRoutes4 = std::make_shared<CDSVReader>(routesrc4,',');
CCSVBusSystem bus4(CSVRStops4, CSVRRoutes4);
EXPECT_EQ(int(CStreetMap::InvalidNodeID), bus4.RouteByIndex(3)->GetStopID(40000));

}


TEST(CSVBusSystem, StopCount_Routes){
// Returns the number of stops on the route 
auto routesrc = std::make_shared <CStringDataSource>("route,stop_id\n$$,22258\n$$,22169\nA,22000\nA,22005\n$$,22007\nA,22011\n$$,22031\nA,22033\nK,2022");/*string*/
auto stopsrc = std::make_shared<CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops = std::make_shared<CDSVReader>(stopsrc,',');
auto CSVRRoutes = std::make_shared<CDSVReader>(routesrc,',');
CCSVBusSystem bus(CSVRStops, CSVRRoutes);
EXPECT_EQ(4, bus.RouteByIndex(4)->StopCount());

auto routesrc2 = std::make_shared <CStringDataSource>("route,stop_id\n$$,22258\n$$,22169\nA,22000\nA,22005\nA,22007\nA,22011\nA,22031\nA,22033\nK,2022");/*string*/
auto stopsrc2 = std::make_shared<CStringDataSource>("stop_id,node_id\n22043,2849810514\n22358,2849805223\n22105,3954294407\n22175,5598639595\n22174,3119663186\n22177,2599137935\n22176,2607436578\n22078,1190339479");/*string*/
auto CSVRStops2 = std::make_shared<CDSVReader>(stopsrc2,',');
auto CSVRRoutes2 = std::make_shared<CDSVReader>(routesrc2,',');
CCSVBusSystem bus2(CSVRStops2, CSVRRoutes2);
EXPECT_EQ(2, bus2.RouteByName("$$")->StopCount());
}
