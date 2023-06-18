#include "BusSystem.h"
#include "CSVBusSystem.h"
#include "StringUtils.h"
#include "CSVBusSystem.h"
#include "DSVReader.h"
#include "StringDataSource.h"
#include <iostream>
#include <vector>
#include <algorithm>

struct CCSVBusSystem::SImplementation {
    // std::shared_ptr<CDSVReader> stop;
    // std::shared_ptr<CDSVReader> route;

    struct SStop : public CBusSystem::SStop{
        ~SStop(){};
        TStopID id;
        CStreetMap::TNodeID nodeid;

        TStopID ID() const noexcept{
            return id;

        }
        CStreetMap::TNodeID NodeID() const noexcept{
            return nodeid;
        }
        


        
    };
    struct SRoute : public CBusSystem::SRoute{
        ~SRoute(){};
        std::string name;
        std::size_t stopcount;
        std::vector<std::string> vect_stopid;
        


        std::string Name() const noexcept{
            return name;
        }
        std::size_t StopCount() const noexcept{
            return stopcount;
        }
        TStopID GetStopID(std::size_t index) const noexcept{
            size_t getstopid;
            // std::cout<<"size of new vector is: "<<vect_stopid.size()<<std::endl;
            if(index < 0 || index >= vect_stopid.size()){
             //   std::cout<<"OUT OF SCOPE"<<std::endl;
                return CBusSystem::InvalidStopID;
            }
            else{
                for(int i = 0; i < vect_stopid.size(); i++){
                 //   std::cout<<"vect["<<i<<"]["<<i - 2<<"] is: "<<vect_stopid[i]<<std::endl;
                    if(i  == ((index + 2) * 2) - 1){
                        getstopid = stol(vect_stopid[i]);
                       // std::cout<<"BANG"<<std::endl;
                    }
                }
            
            
            return getstopid;

            }
            
        }

    };

    std::vector<std::string> stop_vect;
    std::vector<std::string> route_vect;
    std::shared_ptr<SStop> stop_pointer;
    std::shared_ptr<SRoute> route_pointer;

    SImplementation(std::shared_ptr<CDSVReader> stop, std::shared_ptr<CDSVReader> route){
           // std::cout<<"ere";
            stop->ReadRow(stop_vect);
            stop_pointer = std::make_shared<SStop>();
            route->ReadRow(route_vect); 
            route_pointer = std::make_shared<SRoute>();
    }

    std::size_t StopCount() const noexcept{
        if(stop_vect.size() <= 2){
            return 0;
        }
        for(int i = 0; i <stop_vect.size(); i++){
            // std::cout<<"emptyvect[i] is : "<<empty_vect[i]<<std::endl;
        }
        return (stop_vect.size() / 2) - 1;

    }
    std::size_t RouteCount() const noexcept{
        std::vector<std::string> storage;
        if(route_vect.size() <= 2){
            return 0;
        }
        for(int i = 0; i <route_vect.size(); i++){
            // std::cout<<"emptyvect[i] is : "<<empty_vect[i]<<std::endl;
            if(i % 2 == 0){
                // std::cout<<"emptyvect of is is currently:  "<<empty_vect[i]<<std::endl;
                if(!std::count(storage.begin(), storage.end(), route_vect[i])) {
                    storage.push_back(route_vect[i]);
                }
                else {
                    continue;
                }        
            }
        }

        return storage.size() - 1;

    }
    std::shared_ptr<SStop> StopByIndex(std::size_t index) const noexcept{
        int index_counter = 0;
        if(index >= stop_vect.size() / 2 - 1 || index < 0){
            return nullptr;
        }
        for(int i = 0; i <stop_vect.size(); i++){
            // std::cout<<"vect["<<i<<"]["<<i - 2<<"] is: "<<vect[i]<<std::endl;
            if(i == ((index + 2) * 2) - 2){
                
                // std::cout<<"hello, i is curreently: "<<i<<std::endl;
                stop_pointer->id = stol(stop_vect[i]);
                stop_pointer->nodeid = stol(stop_vect[i + 1]);

            }
        }
        



        return stop_pointer;
    }
    std::shared_ptr<SStop> StopByID(TStopID id) const noexcept{
        bool match_found = false;
        for(int i = 2; i < stop_vect.size(); i++){
            if(i % 2 == 0){
                if(stol(stop_vect[i]) == id){
                    // std::cout<<"HERE "<<vect[i]<<std::endl;
                    stop_pointer->id = stol(stop_vect[i]);
                    // std::cout<<"stol of numba is: "<<pointer->id<<std::endl;
                    match_found = true;
                }
            
            }
            if(i % 2 != 0){
                if(match_found == true){
                    stop_pointer->nodeid = stol(stop_vect[i]);
                    // std::cout<<"stol of numba is: "<<pointer->nodeid<<std::endl;
                    break;
                }
            }

            
        }
        if(match_found == false){
            return nullptr;
        }
        
        return stop_pointer;
    }

    std::shared_ptr<SRoute> RouteByIndex(std::size_t index) const noexcept{
        std::size_t count = -1;
        route_pointer->vect_stopid = route_vect;
        int counter = 0;
        std::string placeholder;
        if(index >= route_vect.size() / 2 - 1 || index < 0){
            return nullptr;
        }
        
        for(int i = 2; i <route_vect.size(); i++){
            // std::cout<<"vect["<<i<<"] is: "<<vect[i]<<std::endl;
            if(((index + 2) * 2) - 2 == i){
               // std::cout<<"EZ MONEY"<<std::endl;
                placeholder = route_vect[i];
                route_pointer->name = route_vect[i];
            }
            

        }
        for(int i = 2; i <route_vect.size(); i++){
            if(placeholder == route_vect[i]){
                counter++;
            }
            

        }

        route_pointer->stopcount = counter;
        
        
        
        
        return route_pointer;
    }
    std::shared_ptr<SRoute> RouteByName(const std::string &name)const noexcept{
        bool route_in_vect = false;
        size_t counter = 0;
        for(int i = 2; i < route_vect.size(); i++){
            // std::cout<<"route_vect["<<i<<"] is: "<<route_vect[i]<<std::endl;
            if(route_vect[i] == name){
                route_in_vect = true;
                route_pointer->name = route_vect[i];
                counter++;
                
            }
    
            route_pointer->stopcount = counter;
        }
        route_pointer->vect_stopid = route_vect; 
        if(route_in_vect == false){
            return nullptr;
        }

        return route_pointer;
    }

};

CCSVBusSystem::CCSVBusSystem(std::shared_ptr< CDSVReader > stopsrc, std::shared_ptr< CDSVReader > routesrc){
 DImplementation = std::make_unique<SImplementation>(stopsrc,routesrc);
}


CCSVBusSystem::~CCSVBusSystem(){

}
std::size_t CCSVBusSystem::StopCount() const noexcept{
    return DImplementation->StopCount();

}
std::size_t CCSVBusSystem::RouteCount() const noexcept{
    return DImplementation->RouteCount();

}

std::shared_ptr<CBusSystem::SStop> CCSVBusSystem::StopByIndex(std::size_t index) const noexcept{
    return DImplementation->StopByIndex(index);

}
std::shared_ptr<CBusSystem::SStop> CCSVBusSystem::StopByID(TStopID id) const noexcept{
    return DImplementation->StopByID(id);

}
std::shared_ptr<CBusSystem::SRoute> CCSVBusSystem::RouteByIndex(std::size_t index) const noexcept{
    return DImplementation->RouteByIndex(index);

}
std::shared_ptr<CBusSystem::SRoute> CCSVBusSystem::RouteByName(const std::string &name)const noexcept{
    return DImplementation->RouteByName(name);
}
