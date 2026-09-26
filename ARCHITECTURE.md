OWNERSHIP
_________________________________


StorageManager

↓

Storage (SQLITE3)

_________________________________
main.cpp

↓

launches the code                   

↓

WorldLauncher

takes data from StorageManager 

↓

World

↓

Human, Planet

_________________________________
Human 

↓

Gender


__________________________________



FOLDER STRUCTURE
__________________________________


Cpp_LifeSimulator[
        include[
            gender.h
            human.h
            planet.h
            world.h
            UI.h
            errors.h
            Storage[
                sqlite3_storage.h
                storage.h
                storage_manager.h
            ]
        ]
        lib[
            sqlite3.h
            sqlite3.c
        ]
        src[
            main.cpp
            human.cpp
            UI.cpp
            Storage[
                sqlite3_storage.cpp
                storage_manager.cpp
            ]
        ]
        .gitignore 
        ARCHITECTURE.md
]
__________________________________


SQLITE3 TABLES
__________________________________

players.db:

    |------------------------------------------------------|
    |       | id | name | age  | money  | gender |  job    |
    |------------------------------------------------------|
    |player |    |      |      |        |        |         |
    |------------------------------------------------------|

    id = INTEGER PRIMARY KEY AUTOINCREMENT

    name = TEXT NOT NULL

    money = INTEGER
    
    gender = INTEGER (0 - human, 1 - woman)

    job = TEXT NOT NULL
__________________________________



Data format for Storage 
___________________________________

player_data = std::variant<int,std::string>;
player_data_types = std::map<HumanStats, player_data>; (id,name,age,money,gender);
























