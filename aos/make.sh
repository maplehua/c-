#!/bin/bash
cd server
g++ -o ../start_server $(mysql_config --cflags) mainServer.cpp serversocket.cpp ../library/log/log.cpp ../library/db/dbMysql.cpp $(mysql_config --libs) 

cd ..
cd client
g++ -o ../start_client main.cpp client.cpp ../library/log/log.cpp
