#ifndef HASHTABLEQUAD_H_
#define HASHTABLEQUAD_H_

#include <vector>

class HashTableQuad
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
	HashTableQuad(int maxNum, double load);

	// required methods
	void insert(int n);
	bool isIn(int n);
	void printKeys();
	void printKeysAndIndexes();

    int getNumKeys() {
        return keyNum;
    };

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

	// used for testing
	std::vector<int> getTable() {
		return table;
	};

private:
	// required methods
	void rehash();
};

#endif /* HASHTABLEQUAD_H_ */
