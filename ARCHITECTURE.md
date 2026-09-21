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
            Storage[
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
                storage.cpp
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

    |------------------------------------|
    |       | id | name | money | gender |
    |------------------------------------|
    |player |    |      |       |        |
    |------------------------------------|

    id = INTEGER AUTOINCREMENT

    name = STRING NOT NONE

    money = INTEGER
    
    gender = STRING NOT NONE
__________________________________



























