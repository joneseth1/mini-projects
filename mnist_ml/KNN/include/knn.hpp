#ifndef KNN_H
#define KNN_H

#include <memory>
#include <vector>
#include "data.hpp"

class KNN {
private:
    int k;
    std::vector<std::unique_ptr<Data>> neighbors;
    std::vector<std::unique_ptr<Data>> trainingData;
    std::vector<std::unique_ptr<Data>> testData;
    std::vector<std::unique_ptr<Data>> validationData;

public:
    KNN(int k = 3);
    ~KNN();

    void findKNearest(const Data& queryPoint);
    void setTrainingData(const std::vector<std::unique_ptr<Data>>& data);
    void setTestData(const std::vector<std::unique_ptr<Data>>& data);
    void setValidationData(const std::vector<std::unique_ptr<Data>>& data);
    void setK(int val);

    int predict();
    double calculateDistance(const Data& queryPoint, const Data& input) const;
    double validatePerformance() const;
    double testPerformance() const;
};

#endif
