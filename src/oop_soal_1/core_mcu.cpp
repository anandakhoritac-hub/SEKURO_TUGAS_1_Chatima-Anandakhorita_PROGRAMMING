#include "core_mcu.hpp"
#include <iostream>

// Constructor
Core_MCU::Core_MCU(float cpu_speed, int memory, std::string os, std::string nama, int volt) {
    this->cpu_speed = cpu_speed;
    this->memory = memory;
    this->os = os;
    this->nama = nama;
    this->volt = volt;
    
    
    std::cout << "[Core_MCU] : MCU utama yang bernama " << nama << " telah dibuat" << std::endl;
}

// Method untuk nambah volt
void Core_MCU::nambah_volt(int penambahan_voltase) {
    this->volt += penambahan_voltase;
    std::cout << "[Core_MCU] : MCU utama yang bernama " << nama << " Telah ditambah voltasenya menjadi = " << this->volt << std::endl;
}

// Destructor
Core_MCU::~Core_MCU() {
    std::cout << "[Core_MCU] : MCU utama yang bernama " << nama << " telah dihapus" << std::endl;
}

// Method untuk show spek
void Core_MCU::showSpek() {
    std::cout << "[SPEK DEVICE] : [NAMA_DEVICE]: " << nama 
              << " | [CPU CLOCK] : " << cpu_speed 
              << " | [MEMORY] : " << memory 
              << " | [OS] : " << os << std::endl;
}

// Method untuk ganti os
void Core_MCU::ganti_os(std::string new_os) {
    this->os = new_os;
    std::cout << "[Core_MCU] : MCU utama yang bernama " << nama << " Telah diganti OS nya menjadi = " << os << std::endl;
}


std::string Core_MCU::get_os() {
    return this->os;
}