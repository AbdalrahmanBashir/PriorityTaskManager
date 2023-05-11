#include <iostream>
#include "PriorityQueue.h"
#include <fstream>

void print_menu();
int main() {
    PriorityQueue pq;
    // Declare some variables.
    std::string jobs;
    int choice = 0;
    int priority_choice;
    system("cls");
    while (choice != 8) {
        // Print the menu.
        print_menu();

        // Ask the user for their choice.
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << std::endl;

        // Clear the console screen.
        system("cls");

        // Use a switch statement to perform the appropriate action based on the user's choice.
        switch (choice) {
        case 1: {
            // Add a job to the priority queue.
            std::cout << "Enter job priority (1 = HIGHEST, 5 = LOWEST): ";
            std::cin >> priority_choice;
            Priority priority;
            switch (priority_choice) {
            case 1:
                priority = Priority::LOWEST;
                break;
            case 2:
                priority = Priority::LOW;
                break;
            case 3:
                priority = Priority::MEDIUM;
                break;
            case 4:
                priority = Priority::HIGH;
                break;
            case 5:
                priority = Priority::HIGHEST;
                break;
            default:
                std::cout << "Invalid priority choice" << std::endl;
                continue;
            }

            std::cout << "Enter job description: ";
            std::string description;
            std::cin.ignore();
            std::getline(std::cin, description);

            pq.add_job(Job(priority, description));
            std::cout << "Job added successfully" << std::endl;
            break;
        }
        case 2: {
            // Remove a job from the priority queue.
            if (pq.remove_job()) {
                std::cout << "Job removed successfully" << std::endl;
            }
            else {
                std::cout << "Priority queue is empty" << std::endl;
            }
            break;
        }
        case 3: {
            // Get the highest priority job in the priority queue.
            try {
                Job job = pq.get_highest_priority_job();
                std::cout << "Next job: " << job.description << std::endl;
            }
            catch (const std::logic_error& e) {
                std::cout << e.what() << std::endl;
            }
            break;
        }
        case 4: {
            // Get the number of jobs in the priority queue.
            std::cout << "Number of jobs in priority queue: " << pq.get_num_jobs() << std::endl;
            break;
        }
        case 5: {
            // Save the jobs in the priority queue to a file.
            pq.write_jobs("Task.txt");
            std::cout << std::endl;
            std::cout << "Jobs saved successfully" << std::endl;
            break;
        }
        case 6: {
            // Load the jobs from a file into the priority queue.
            pq.read_jobs("Task.txt");
            std::cout << "Jobs loaded successfully" << std::endl;
        }
        case 7: {
            std::cout << "Exiting program" << std::endl;
            break;
        }
        default: {
            // Handle an invalid choice.
            std::cout << "Invalid choice" << std::endl;
            break;
        }
        }
        std::cout << std::endl;
    }
        return 0;
    }


    void print_menu() {
        std::cout << "----------------------------------" << std::endl;
        std::cout << "Priority Queue Menu:" << std::endl;
        std::cout << "1. Add Job" << std::endl;
        std::cout << "2. Remove Job" << std::endl;
        std::cout << "3. Get Highest Priority Job" << std::endl;
        std::cout << "4. Get Number of Jobs" << std::endl;
        std::cout << "5. Save your Jobs" << std::endl;
        std::cout << "6. Loading Jobs to the Queue" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "----------------------------------" << std::endl;
    }
