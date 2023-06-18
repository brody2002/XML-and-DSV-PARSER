CC=gcc
CXX=g++

INC_DIR=./include
SRC_DIR=./src
TESTSRC_DIR=./testsrc

BIN_DIR=./bin
OBJ_DIR=./obj

CXXFLAG=-std=gnu++17 -I $(INC_DIR) -I /opt/local/include
LDFLAGS=-L /opt/local/lib -lgtest -lgtest_main -lpthread -lexpat

all: directories DSVTest CSVBusSystemTest OpenStreetMapTest

DataSourceTest: $(BIN_DIR)/DataSourceTest
	$(BIN_DIR)/DataSourceTest

$(BIN_DIR)/DataSourceTest: $(OBJ_DIR)/DataSourceTest.o $(OBJ_DIR)/StringDataSource.o
	$(CXX) -o $(BIN_DIR)/DataSourceTest $(OBJ_DIR)/DataSourceTest.o $(OBJ_DIR)/StringDataSource.o $(LDFLAGS)

$(OBJ_DIR)/DataSourceTest.o: $(SRC_DIR)/StringDataSource.cpp $(INC_DIR)/StringDataSource.h $(INC_DIR)/DataSource.h
	$(CXX) -o $(OBJ_DIR)/DataSourceTest.o $(CXXFLAG) -c $(TESTSRC_DIR)/StringDataSourceTest.cpp

$(OBJ_DIR)/StringDataSource.o: $(SRC_DIR)/StringDataSource.cpp $(INC_DIR)/StringDataSource.h $(INC_DIR)/DataSource.h
	$(CXX) -o $(OBJ_DIR)/StringDataSource.o $(CXXFLAG) -c $(SRC_DIR)/StringDataSource.cpp

DataSinkTest: $(BIN_DIR)/DataSinkTest
	$(BIN_DIR)/DataSinkTest

$(BIN_DIR)/DataSinkTest: $(OBJ_DIR)/DataSinkTest.o $(OBJ_DIR)/StringDataSink.o
	$(CXX) -o $(BIN_DIR)/DataSinkTest $(OBJ_DIR)/DataSinkTest.o $(OBJ_DIR)/StringDataSink.o $(LDFLAGS)

$(OBJ_DIR)/DataSinkTest.o: $(SRC_DIR)/StringDataSink.cpp $(INC_DIR)/StringDataSink.h $(INC_DIR)/DataSink.h
	$(CXX) -o $(OBJ_DIR)/DataSinkTest.o $(CXXFLAG) -c $(TESTSRC_DIR)/StringDataSinkTest.cpp

$(OBJ_DIR)/StringDataSink.o: $(SRC_DIR)/StringDataSink.cpp $(INC_DIR)/StringDataSink.h $(INC_DIR)/DataSink.h
	$(CXX) -o $(OBJ_DIR)/StringDataSink.o $(CXXFLAG) -c $(SRC_DIR)/StringDataSink.cpp

DSVTest: $(BIN_DIR)/DSVTest
	$(BIN_DIR)/DSVTest

$(BIN_DIR)/DSVTest: $(OBJ_DIR)/DSVTest.o $(OBJ_DIR)/DSVWriter.o $(OBJ_DIR)/DSVReader.o $(OBJ_DIR)/StringDataSource.o $(OBJ_DIR)/StringDataSink.o $(OBJ_DIR)/StringUtils.o
	$(CXX) -o $(BIN_DIR)/DSVTest $(OBJ_DIR)/DSVTest.o $(OBJ_DIR)/DSVWriter.o $(OBJ_DIR)/DSVReader.o $(LDFLAGS) $(OBJ_DIR)/StringDataSource.o $(OBJ_DIR)/StringDataSink.o $(OBJ_DIR)/StringUtils.o

$(OBJ_DIR)/DSVTest.o: $(TESTSRC_DIR)/DSVTest.cpp $(INC_DIR)/DSVWriter.h $(INC_DIR)/DSVReader.h
	$(CXX) -o $(OBJ_DIR)/DSVTest.o $(CXXFLAG) -c $(TESTSRC_DIR)/DSVTest.cpp

$(OBJ_DIR)/DSVWriter.o: $(SRC_DIR)/DSVWriter.cpp $(INC_DIR)/DSVWriter.h
	$(CXX) -o $(OBJ_DIR)/DSVWriter.o $(CXXFLAG) -c $(SRC_DIR)/DSVWriter.cpp

$(OBJ_DIR)/DSVReader.o: $(SRC_DIR)/DSVReader.cpp $(INC_DIR)/DSVReader.h
	$(CXX) -o $(OBJ_DIR)/DSVReader.o $(CXXFLAG) -c $(SRC_DIR)/DSVReader.cpp 

$(OBJ_DIR)/StringUtils.o: $(SRC_DIR)/StringUtils.cpp $(INC_DIR)/StringUtils.h
	$(CXX) -o $(OBJ_DIR)/StringUtils.o $(CXXFLAG) -c $(SRC_DIR)/StringUtils.cpp

XMLTest: $(BIN_DIR)/XMLTest
	$(BIN_DIR)/XMLTest

$(BIN_DIR)/XMLTest: $(OBJ_DIR)/XMLTest.o $(OBJ_DIR)/XMLReader.o $(OBJ_DIR)/XMLWriter.o $(OBJ_DIR)/StringDataSource.o $(OBJ_DIR)/StringDataSink.o $(OBJ_DIR)/StringUtils.o
	$(CXX) -o $(BIN_DIR)/XMLTest $(OBJ_DIR)/XMLTest.o $(OBJ_DIR)/XMLReader.o $(OBJ_DIR)/XMLWriter.o $(LDFLAGS) $(OBJ_DIR)/StringDataSource.o $(OBJ_DIR)/StringDataSink.o $(OBJ_DIR)/StringUtils.o

$(OBJ_DIR)/XMLTest.o: $(TESTSRC_DIR)/XMLTest.cpp $(INC_DIR)/XMLReader.h $(INC_DIR)/XMLWriter.h $(INC_DIR)/XMLEntity.h
	$(CXX) -o $(OBJ_DIR)/XMLTest.o $(CXXFLAG) -c $(TESTSRC_DIR)/XMLTest.cpp

$(OBJ_DIR)/XMLReader.o: $(SRC_DIR)/XMLReader.cpp $(INC_DIR)/XMLReader.h $(INC_DIR)/XMLEntity.h
	$(CXX) -o $(OBJ_DIR)/XMLReader.o $(CXXFLAG) -c $(SRC_DIR)/XMLReader.cpp

$(OBJ_DIR)/XMLWriter.o: $(SRC_DIR)/XMLWriter.cpp $(INC_DIR)/XMLWriter.h
	$(CXX) -o $(OBJ_DIR)/XMLWriter.o $(CXXFLAG) -c $(SRC_DIR)/XMLWriter.cpp

CSVBusSystemTest: $(BIN_DIR)/CSVBusSystemTest
	$(BIN_DIR)/CSVBusSystemTest

$(BIN_DIR)/CSVBusSystemTest: $(OBJ_DIR)/CSVBusSystemTest.o $(OBJ_DIR)/CSVBusSystem.o $(OBJ_DIR)/DSVReader.o $(OBJ_DIR)/DSVWriter.o $(OBJ_DIR)/StringDataSource.o $(OBJ_DIR)/StringDataSink.o $(OBJ_DIR)/StringUtils.o
	$(CXX) -o $(BIN_DIR)/CSVBusSystemTest $(OBJ_DIR)/CSVBusSystemTest.o $(OBJ_DIR)/CSVBusSystem.o $(OBJ_DIR)/DSVReader.o $(OBJ_DIR)/DSVWriter.o $(OBJ_DIR)/StringDataSource.o $(OBJ_DIR)/StringDataSink.o $(OBJ_DIR)/StringUtils.o $(LDFLAGS)

$(OBJ_DIR)/CSVBusSystemTest.o: $(TESTSRC_DIR)/CSVBusSystemTest.cpp $(INC_DIR)/BusSystem.h $(INC_DIR)/CSVBusSystem.h
	$(CXX) -o $(OBJ_DIR)/CSVBusSystemTest.o $(CXXFLAG) -c $(TESTSRC_DIR)/CSVBusSystemTest.cpp

$(OBJ_DIR)/CSVBusSystem.o: $(SRC_DIR)/CSVBusSystem.cpp $(INC_DIR)/BusSystem.h $(INC_DIR)/CSVBusSystem.h
	$(CXX) -o $(OBJ_DIR)/CSVBusSystem.o $(CXXFLAG) -c $(SRC_DIR)/CSVBusSystem.cpp


OpenStreetMapTest: $(BIN_DIR)/OpenStreetMapTest
	$(BIN_DIR)/OpenStreetMapTest

$(BIN_DIR)/OpenStreetMapTest: $(OBJ_DIR)/OpenStreetMapTest.o $(OBJ_DIR)/OpenStreetMap.o $(OBJ_DIR)/XMLReader.o $(OBJ_DIR)/XMLWriter.o $(OBJ_DIR)/StringDataSource.o $(OBJ_DIR)/StringDataSink.o $(OBJ_DIR)/StringUtils.o
	$(CXX) -o $(BIN_DIR)/OpenStreetMapTest $(OBJ_DIR)/OpenStreetMapTest.o $(OBJ_DIR)/OpenStreetMap.o $(LDFLAGS) $(OBJ_DIR)/XMLReader.o $(OBJ_DIR)/XMLWriter.o $(OBJ_DIR)/StringDataSource.o $(OBJ_DIR)/StringDataSink.o $(OBJ_DIR)/StringUtils.o $(LDFLAGS)
	
$(OBJ_DIR)/OpenStreetMapTest.o: $(TESTSRC_DIR)/OpenStreetMapTest.cpp $(INC_DIR)/OpenStreetMap.h $(INC_DIR)/StreetMap.h
	$(CXX) -o $(OBJ_DIR)/OpenStreetMapTest.o $(CXXFLAG) -c $(TESTSRC_DIR)/OpenStreetMapTest.cpp

$(OBJ_DIR)/OpenStreetMap.o: $(SRC_DIR)/OpenStreetMap.cpp $(INC_DIR)/OpenStreetMap.h $(INC_DIR)/StreetMap.h $(INC_DIR)/XMLEntity.h $(INC_DIR)/XMLReader.h
	$(CXX) -o $(OBJ_DIR)/OpenStreetMap.o $(CXXFLAG) -c $(SRC_DIR)/OpenStreetMap.cpp

directories:
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)

.PHONY: clean

clean:
	@echo "🧹 Clearing..."
	rm -rf $(BIN_DIR) $(OBJ_DIR)
