#include <iostream>
#include <vector>
#include <numeric>
#include <future>

// Function to accumulate elements in a vector<double> range
double accumulateHalf(const std::vector<double>& vec, size_t start, size_t end) {
    return std::accumulate(vec.begin() + start, vec.begin() + end, 0.0);
}

int main() {
    // Create a vector of doubles
    std::vector<double> numbers = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};

    // Divide the vector into two halves
    size_t half_size = numbers.size() / 2;

    // Create packaged tasks for accumulating each half
    std::packaged_task<double(const std::vector<double>&, size_t, size_t)> task1(accumulateHalf);
    std::packaged_task<double(const std::vector<double>&, size_t, size_t)> task2(accumulateHalf);

    // Get futures from the packaged tasks
    std::future<double> future1 = task1.get_future();
    std::future<double> future2 = task2.get_future();

    // Execute the tasks concurrently on each half of the vector
    std::thread thread1(std::move(task1), std::ref(numbers), 0, half_size);
    std::thread thread2(std::move(task2), std::ref(numbers), half_size, numbers.size());

    // Wait for both threads to finish and get the results
    thread1.join();
    thread2.join();

    // Get the results from the futures
    double result1 = future1.get();
    double result2 = future2.get();

    // Calculate the final sum by adding the results of the two halves
    double finalSum = result1 + result2;

    // Print the final sum
    std::cout << "Final Sum: " << finalSum << std::endl;

    return 0;
}
