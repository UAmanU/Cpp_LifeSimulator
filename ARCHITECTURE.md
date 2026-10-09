_________________________________

ALL comments for explanation are written in declaration files (and main.cpp) of each class/struct/enum class and etc. object!

IDK why but Include, Src and Lib folders are lower case in github. It's capitalize in my laptop!
_________________________________



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

ProgrammLauncher

takes data from StorageManager , catches errors and calls GUI functions.

↓

World

↓

owns and controlls
Human, Planet

_________________________________
Human 

↓

Gender, Job


__________________________________



FOLDER STRUCTURE
__________________________________


Cpp_LifeSimulator[
        Include[
            programm_launcher.h
            Human[
                gender.h
                human.h
                action.h
            ]
            World[
                planet.h
                world.h
            ]
            errors.h
            Storage[
                config_manager.h
                sqlite3_storage.h
                storage.h
                storage_manager.h
            ]
            Job[
                job.h
                job_types.h
            ]
            GUI[
                input_handler.h
                display_handler.h
            ]
        ]
        Lib[
            sqlite3.h
            sqlite3.c
        ]
        Src[
            main.cpp
            programm_launcher.cpp
            Human[
                human.cpp
                gender.cpp
                action.cpp
            ]
            World[
                world.cpp
                planet.cpp
            ]
            GUI[
                display_handler.cpp
                input_handler.cpp
            ]
            Storage[
                config_manager.cpp
                sqlite3_storage.cpp
                storage_manager.cpp
            ]
            Job[
                job.cpp
                job_types.cpp
            ]
        ]
        .gitignore 
        ARCHITECTURE.md
]
__________________________________


SQLITE3 TABLES
__________________________________

players.db:

    |---------------------------------------------------------------|
    |       | id | name | age  | money  | gender |  job    | salary |
    |---------------------------------------------------------------|
    |player |    |      |      |        |        |         |        |
    |---------------------------------------------------------------|

    id = INTEGER PRIMARY KEY AUTOINCREMENT

    name = TEXT NOT NULL

    money = INTEGER
    
    gender = INTEGER (0 - human, 1 - woman)

    job = TEXT NOT NULL
    
    salary = INTEGER
__________________________________



Data format for Storage 
___________________________________

    raw_data = std::variant<int,std::string>;
    player_data_types = std::map<HumanStats, player_data>; (id,name,age,money,gender);


___________________________________


Job System
___________________________________

    struct Job;
    enum class JobType;

Warning: Job isn't a complex object which needs to be realised in 100-200 lines of code.
But there's a folder named Job in both src and include folders for better updates.
___________________________________






































