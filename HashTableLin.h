#ifndef HASHTABLELIN_H_
#define HASHTABLELIN_H_

#include <vector>

class HashTableLin
{
private:
	// must contain this private field
	std::vector<int> table;
	// define other private fields to store:
	// 1. the size of the table
    int size;
	// 2. the number of keys stored in the table
    int keyNum;
	// 3. the maximum load factor allowed
    double load;

public:
	// required constructor
	HashTableLin(int maxNum, double load);

	// required methods
	void insert(int n);
	bool isIn(int n);
	void printKeys();
	void printKeysAndIndexes();

    int getNumKeys() {
        return keyNum;
    };

    void addKeyNum() {
        keyNum++;
    }

    int getTableSize() {
        return size;
    };

    void setTableSize(int s) {
        size = s;
    }

    double getMaxLoadFactor() {
        return load;
    };

    void setMaxLoadFactor(double l) {
        load = l;
    }

	static std::vector<double> simProbeSuccess();
	static std::vector<double> simProbeUnsuccess(); // for bonus

	// used for testing
	std::vector<int> getTable() {
		return table;
	};

    void setTable(std::vector<int> t) {
        table = t;
    }

private:
	// required methods
	void rehash();
};

#endif /* HASHTABLELIN_H_ */
