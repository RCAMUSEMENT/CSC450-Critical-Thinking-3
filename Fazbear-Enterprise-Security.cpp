#include <iostream>
#include <limits>
#include <new>
#include <string>

// Trap bad keyboard strings before they snap our input streams into a permanent spin loop
int getValidatedSecurityMetric(const std::string& prompt) {
    int validatedInput = 0;
    std::cout << prompt;

    // Catch alphabet strings or typo noise if someone keys in names instead of metrics
    while (!(std::cin >> validatedInput)) {
        std::cout << "SYSTEM ERROR: Invalid telemetry data. Enter a valid integer: ";
        std::cin.clear(); // Pop the fail bit off the input pipeline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Dump the leftover junk characters
    }
    return validatedInput;
}

int main() {
    std::cout << "====================================================\n";
    std::cout << "      FAZBEAR ENTERPRISE SECURITY OS: MOD 3         \n";
    std::cout << "====================================================\n\n";

    // Allocating primitive stack spaces to hold initial telemetry tokens
    int powerGridLevel = 0;
    int cameraStaticDb = 0;
    int animatronicProximity = 0;

    // Run inputs through defensive tracking filters
    powerGridLevel = getValidatedSecurityMetric("Enter current Power Grid Percentage (0-100): ");
    cameraStaticDb = getValidatedSecurityMetric("Enter Camera System Static Decibels: ");
    animatronicProximity = getValidatedSecurityMetric("Enter Animatronic Hallway Proximity Units: ");
    std::cout << "\nTelemetry captured. Mapping metrics to live heap registers...\n\n";

    // Set up pointer channels as safe null handles before pointing to physical addresses
    int* powerRegPtr = nullptr;
    int* staticRegPtr = nullptr;
    int* proxRegPtr = nullptr;

    try {
        // Drop the stack primitives onto isolated raw heap allocations using new
        powerRegPtr = new int(powerGridLevel);
        staticRegPtr = new int(cameraStaticDb);
        proxRegPtr = new int(animatronicProximity);
    }
    catch (const std::bad_alloc& allocationException) {
        // Panic block fires if the machine silicon runs entirely out of allocatable page space
        std::cerr << "CRITICAL SUB-SYSTEM FAILURE: Heap allocation error: " << allocationException.what() << "\n";

        // Defensive dump pattern to drop allocations if the runtime breaks halfway through
        delete powerRegPtr;
        delete staticRegPtr;
        delete proxRegPtr;
        return 1;
    }

    std::cout << "----------------------------------------------------\n";
    std::cout << "     Office Dashboard Logs (Stack Segmentation)     \n";
    std::cout << "----------------------------------------------------\n";
    std::cout << "Variable powerGridLevel Address:  " << &powerGridLevel << " | Value: " << powerGridLevel << "%\n";
    std::cout << "Variable cameraStaticDb Address:  " << &cameraStaticDb << " | Value: " << cameraStaticDb << " dB\n";
    std::cout << "Variable animatronicProximity Address: " << &animatronicProximity << " | Value: " << animatronicProximity << " units\n\n";

    std::cout << "----------------------------------------------------\n";
    std::cout << "    Dynamic Monitor Overrides (Heap Segmentation)   \n";
    std::cout << "----------------------------------------------------\n";
    std::cout << "Pointer powerRegPtr Target Location:  " << powerRegPtr  << " | Live Override Value: " << *powerRegPtr << "\n";
    std::cout << "Pointer staticRegPtr Target Location: " << staticRegPtr  << " | Live Override Value: " << *staticRegPtr << "\n";
    std::cout << "Pointer proxRegPtr Target Location:   " << proxRegPtr    << " | Live Override Value: " << *proxRegPtr << "\n\n";

    std::cout << "6:00 AM Shift Concluded. Shutting down systems and clearing heap registers...\n";

    // Clean reclamation block to wipe our spatial tracking addresses and bypass memory leaks
    if (powerRegPtr != nullptr) {
        delete powerRegPtr;     // Free the dynamic memory allocation back to system space
        powerRegPtr = nullptr;  // Kill the dangling reference trap to protect future pointer reads
    }
    if (staticRegPtr != nullptr) {
        delete staticRegPtr;
        staticRegPtr = nullptr;
    }
    if (proxRegPtr != nullptr) {
        delete proxRegPtr;
        proxRegPtr = nullptr;
    }

    std::cout << "Main power terminal disconnected. Safe execution sequence complete.\n";
    std::cout << "====================================================\n";

    return 0;
}