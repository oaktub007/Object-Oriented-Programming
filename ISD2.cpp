#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Forward declaration of classes
class User;
class Job;
class HelpdeskSystem;

// Class representing a user
class User {
private:
    std::string username;
    std::string email;

public:
    User(const std::string& username, const std::string& email) : username(username), email(email) {}

    std::string getUsername() const {
        return username;
    }

    std::string getEmail() const {
        return email;
    }
};

// Class representing a job
class Job {
private:
    std::string title;
    std::string description;
    User* createdBy;
    User* assignedTo;
    std::string status;

public:
    Job(const std::string& title, const std::string& description, User* createdBy)
        : title(title), description(description), createdBy(createdBy), assignedTo(nullptr), status("Pending") {}

    void assignTo(User* user) {
        assignedTo = user;
        status = "Assigned";
    }

    void complete() {
        status = "Completed";
    }

    std::string getTitle() const {
        return title;
    }

    std::string getDescription() const {
        return description;
    }

    std::string getStatus() const {
        return status;
    }

    std::string getAssignedTo() const {
        return assignedTo ? assignedTo->getUsername() : "Unassigned";
    }
};

// Class representing the Helpdesk system
class HelpdeskSystem {
private:
    std::unordered_map<std::string, User*> users;
    std::vector<Job*> jobs;

public:
    // Method to create a new user profile or retrieve existing user
    User* getUser(const std::string& username, const std::string& email) {
        if (users.find(username) != users.end()) {
            return users[username];
        } else {
            User* newUser = new User(username, email);
            users[username] = newUser;
            return newUser;
        }
    }

    // Method to log a new job
    void logJob(const std::string& title, const std::string& description, const std::string& username) {
        User* user = getUser(username, "");
        Job* newJob = new Job(title, description, user);
        jobs.push_back(newJob);
        std::cout << "Job logged successfully.\n";
    }

    // Method to allocate a job to helpdesk staff
    void allocateJob(Job* job, const std::string& assignee) {
        User* user = getUser(assignee, "");
        job->assignTo(user);
        std::cout << "Job assigned to " << assignee << ".\n";
    }

    // Method to complete a job
    void completeJob(Job* job) {
        job->complete();
        std::cout << "Job '" << job->getTitle() << "' marked as completed.\n";
    }

    // Method to display all jobs
    void displayJobs() {
        std::cout << "Jobs:\n";
        for (Job* job : jobs) {
            std::cout << "Title: " << job->getTitle() << "\n";
            std::cout << "Description: " << job->getDescription() << "\n";
            std::cout << "Status: " << job->getStatus() << "\n";
            std::cout << "Assigned to: " << job->getAssignedTo() << "\n\n";
        }
    }
};

int main() {
    HelpdeskSystem helpdesk;

    // Simulating usage
    helpdesk.logJob("Network issue", "Unable to connect to the internet", "john_doe");
    helpdesk.logJob("Software installation", "Need to install new software", "jane_smith");

    helpdesk.allocateJob(helpdesk.getUser("Network issue", ""), "helpdesk_staff1");
    helpdesk.allocateJob(helpdesk.getUser("Software installation", ""), "helpdesk_staff2");

    helpdesk.completeJob(helpdesk.allocateJob(helpdesk.getUser("Network issue", ""), "helpdesk_staff1"));

    helpdesk.displayJobs();

    return 0;
}
