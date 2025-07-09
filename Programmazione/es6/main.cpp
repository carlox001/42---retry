#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Histogram {
private:
    std::vector<std::string>	names;
    std::vector<int>			counts;
    bool percentDisplay = false;

public:
    Histogram(const std::vector<std::string>& classNames)
        : names(classNames), counts(classNames.size(), 0) {}

    void setCount(size_t index, int count) {
        if (index < counts.size()) {
            counts[index] = count;
        }
    }

    int getCount(size_t index) const {
        if (index < counts.size()) {
            return counts[index];
        }
        return -1;
    }

    void setDisplayAsPercent(bool percent) {
        percentDisplay = percent;
    }

    void show() const {
        int total;

        total = 0;
        for (int count : counts)
            total += count;
        std::cout << "\n--- ISTOGRAMMA ---\n";
        for (size_t i = 0; i < names.size(); ++i) {
            std::cout << std::setw(10) << names[i] << " | ";
            int value = counts[i];
            // stampa #
            for (int j = 0; j < value; ++j) {std::cout << '#';}
            if (percentDisplay)
                std::cout << " (" << std::fixed << std::setprecision(1) << (double)value / total * 100 << "%)";
            else
                std::cout << " (" << value << ")";

            std::cout << '\n';
        }
    }
};

int main() {
    std::vector<std::string> categorie = {"Gatti", "Cani", "Uccelli", "Pesci"};
    Histogram h(categorie);

    h.setCount(0, 10);
    h.setCount(1, 15);
    h.setCount(2, 5);
    h.setCount(3, 20);

    h.setDisplayAsPercent(false);
    h.show();

    h.setDisplayAsPercent(true);
    h.show();

    return 0;
}
