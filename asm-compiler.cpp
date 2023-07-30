#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bitset>
#include <sstream>

bool startsWith(const std::string& str, const std::string& prefix) {
    return str.find(prefix) == 0;
}

std::vector<std::string> splitString(const std::string& input, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream stream(input);
    std::string token;

    while (std::getline(stream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

void removeSubstring(std::string& originalString, const std::string& substringToRemove) {
    size_t pos = originalString.find(substringToRemove);
    while (pos != std::string::npos) {
        originalString.erase(pos, substringToRemove.length());
        pos = originalString.find(substringToRemove);
    }
}

std::bitset<32> hexToBinary(const std::string& hexString) {
    std::bitset<32> binaryValue;
    size_t bitIndex = 0;

    for (char c : hexString) {
        int hexDigit;
        if (c >= '0' && c <= '9')
            hexDigit = c - '0';
        else if (c >= 'A' && c <= 'F')
            hexDigit = c - 'A' + 10;
        else if (c >= 'a' && c <= 'f')
            hexDigit = c - 'a' + 10;
        else {
            std::cout << "Invalid hexadecimal digit: " << c << std::endl;
            return binaryValue;
        }

        for (int i = 3; i >= 0; i--) {
            binaryValue[bitIndex++] = hexDigit & (1 << i);
        }
    }

    return binaryValue;
}

int main(int argc, char *argv)
{
    using namespace std;
    bitset<5> opcode;
    bitset<4> rd;
    bitset<4> rs1;
    bitset<4> rs2;
    bitset<15> imm;

    if (argc == 0) {
        ifstream file;

        file.open("main.asm", ios::in);
        if (!file.is_open()) {
            std::cout << "Error opening the file: main.asm" << std::endl;
            return 1;
        }
        string line;
        vector<string> lines;
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();

        for (int i = 0; i < lines.size(); i++) {
            string l = lines[i];
            removeSubstring(l, ",");
            vector<string> code = splitString(l, *" ");

            if (code[0] == "add") {
                opcode = 00000;
                rd = stoi(code[1]); rs1 = stoi(code[2]);
                if (startsWith(code[3], "0x") || startsWith(code[3], "0b") || startsWith(code[3], "0d")) {
                    if (startsWith(code[3], "0x")) {
                        imm = stoi(hexToBinary(code[3].substr(2)).to_string().substr(15));
                    }
                    else if (startsWith(code[3], "0b")) {
                        imm = stoi(code[3].substr(2));
                    }
                    else if (startsWith(code[3], "0d")) {
                        imm = stoi(code[3].substr(2), nullptr, 2);
                    }
                }
                else {
                    rs2 = stoi(code[3]);
                }
            }
            if (code[0] == "sub") {
                opcode = 00001;
                rd = stoi(code[1]); rs1 = stoi(code[2]);
                if (startsWith(code[3], "0x") || startsWith(code[3], "0b") || startsWith(code[3], "0d")) {
                    if (startsWith(code[3], "0x")) {
                        imm = stoi(hexToBinary(code[3].substr(2)).to_string().substr(15));
                    }
                    else if (startsWith(code[3], "0b")) {
                        imm = stoi(code[3].substr(2));
                    }
                    else if (startsWith(code[3], "0d")) {
                        imm = stoi(code[3].substr(2), nullptr, 2);
                    }
                }
                else {
                    rs2 = stoi(code[3]);
                }
            }
            if (code[0] == "or") {
                opcode = 00010;
                rd = stoi(code[1]); rs1 = stoi(code[2]);
                if (startsWith(code[3], "0x") || startsWith(code[3], "0b") || startsWith(code[3], "0d")) {
                    if (startsWith(code[3], "0x")) {
                        imm = stoi(hexToBinary(code[3].substr(2)).to_string().substr(15));
                    }
                    else if (startsWith(code[3], "0b")) {
                        imm = stoi(code[3].substr(2));
                    }
                    else if (startsWith(code[3], "0d")) {
                        imm = stoi(code[3].substr(2), nullptr, 2);
                    }
                }
                else {
                    rs2 = stoi(code[3]);
                }
            }
            if (code[0] == "and") {
                opcode = 00011;
                rd = stoi(code[1]); rs1 = stoi(code[2]);
                if (startsWith(code[3], "0x") || startsWith(code[3], "0b") || startsWith(code[3], "0d")) {
                    if (startsWith(code[3], "0x")) {
                        imm = stoi(hexToBinary(code[3].substr(2)).to_string().substr(15));
                    }
                    else if (startsWith(code[3], "0b")) {
                        imm = stoi(code[3].substr(2));
                    }
                    else if (startsWith(code[3], "0d")) {
                        imm = stoi(code[3].substr(2), nullptr, 2);
                    }
                }
                else {
                    rs2 = stoi(code[3]);
                }
            }
            if (code[0] == "xor") {
                opcode = 00100;
                rd = stoi(code[1]); rs1 = stoi(code[2]);
                if (startsWith(code[3], "0x") || startsWith(code[3], "0b") || startsWith(code[3], "0d")) {
                    if (startsWith(code[3], "0x")) {
                        imm = stoi(hexToBinary(code[3].substr(2)).to_string().substr(15));
                    }
                    else if (startsWith(code[3], "0b")) {
                        imm = stoi(code[3].substr(2));
                    }
                    else if (startsWith(code[3], "0d")) {
                        imm = stoi(code[3].substr(2), nullptr, 2);
                    }
                }
                else {
                    rs2 = stoi(code[3]);
                }
            }
            if (code[0] == "nor") {
                opcode = 00101;
                rd = stoi(code[1]); rs1 = stoi(code[2]);
                if (startsWith(code[3], "0x") || startsWith(code[3], "0b") || startsWith(code[3], "0d")) {
                    if (startsWith(code[3], "0x")) {
                        imm = stoi(hexToBinary(code[3].substr(2)).to_string().substr(15));
                    }
                    else if (startsWith(code[3], "0b")) {
                        imm = stoi(code[3].substr(2));
                    }
                    else if (startsWith(code[3], "0d")) {
                        imm = stoi(code[3].substr(2), nullptr, 2);
                    }
                }
                else {
                    rs2 = stoi(code[3]);
                }
            }
            if (code[0] == "and") {
                opcode = 00110;
                rd = stoi(code[1]); rs1 = stoi(code[2]);
                if (startsWith(code[3], "0x") || startsWith(code[3], "0b") || startsWith(code[3], "0d")) {
                    if (startsWith(code[3], "0x")) {
                        imm = stoi(hexToBinary(code[3].substr(2)).to_string().substr(15));
                    }
                    else if (startsWith(code[3], "0b")) {
                        imm = stoi(code[3].substr(2));
                    }
                    else if (startsWith(code[3], "0d")) {
                        imm = stoi(code[3].substr(2), nullptr, 2);
                    }
                }
                else {
                    rs2 = stoi(code[3]);
                }
            }
            if (code[0] == "xor") {
                opcode = 00111;
                rd = stoi(code[1]); rs1 = stoi(code[2]);
                if (startsWith(code[3], "0x") || startsWith(code[3], "0b") || startsWith(code[3], "0d")) {
                    if (startsWith(code[3], "0x")) {
                        imm = stoi(hexToBinary(code[3].substr(2)).to_string().substr(15));
                    }
                    else if (startsWith(code[3], "0b")) {
                        imm = stoi(code[3].substr(2));
                    }
                    else if (startsWith(code[3], "0d")) {
                        imm = stoi(code[3].substr(2), nullptr, 2);
                    }
                }
                else {
                    rs2 = stoi(code[3]);
                }
            }
            if (code[0] == "sll") {
                opcode = 01000;
                rd = stoi(code[1]); rs1 = stoi(code[2]);
                if (startsWith(code[3], "0x") || startsWith(code[3], "0b") || startsWith(code[3], "0d")) {
                    if (startsWith(code[3], "0x")) {
                        imm = stoi(hexToBinary(code[3].substr(2)).to_string().substr(15));
                    }
                    else if (startsWith(code[3], "0b")) {
                        imm = stoi(code[3].substr(2));
                    }
                    else if (startsWith(code[3], "0d")) {
                        imm = stoi(code[3].substr(2), nullptr, 2);
                    }
                }
                else {
                    rs2 = stoi(code[3]);
                }
            }
            if (code[0] == "srl") {
                opcode = 01001;
                rd = stoi(code[1]); rs1 = stoi(code[2]);
                if (startsWith(code[3], "0x") || startsWith(code[3], "0b") || startsWith(code[3], "0d")) {
                    if (startsWith(code[3], "0x")) {
                        imm = stoi(hexToBinary(code[1].substr(2)).to_string().substr(15));
                    }
                    else if (startsWith(code[3], "0b")) {
                        imm = stoi(code[3].substr(2));
                    }
                    else if (startsWith(code[3], "0d")) {
                        imm = stoi(code[3].substr(2), nullptr, 2);
                    }
                }
                else {
                    rs2 = stoi(code[3]);
                }
            }
            if (code[0] == "sra") {
                opcode = 01010;
                rd = stoi(code[1]); rs1 = stoi(code[2]);
                if (startsWith(code[3], "0x") || startsWith(code[3], "0b") || startsWith(code[3], "0d")) {
                    if (startsWith(code[3], "0x")) {
                        imm = stoi(hexToBinary(code[1].substr(2)).to_string().substr(15));
                    }
                    else if (startsWith(code[3], "0b")) {
                        imm = stoi(code[3].substr(2));
                    }
                    else if (startsWith(code[3], "0d")) {
                        imm = stoi(code[3].substr(2), nullptr, 2);
                    }
                }
                else {
                    rs2 = stoi(code[3]);
                }
            }
            if (code[0] == "bez") {
                opcode = 01011;
                rd = 0001;
                if (startsWith(code[2], "0x")) {
                    imm = stoi(hexToBinary(code[2].substr(2)).to_string().substr(15));
                }
                else if (startsWith(code[2], "0b")) {
                    imm = stoi(code[2].substr(2));
                }
                else if (startsWith(code[2], "0d")) {
                    imm = stoi(code[2].substr(2), nullptr, 2);
                }

                rs1 = stoi(code[1]);
            }
            if (code[0] == "bnz") {
                opcode = 01011;
                rd = 0010;
                if (startsWith(code[2], "0x")) {
                    imm = stoi(hexToBinary(code[2].substr(2)).to_string().substr(15));
                }
                else if (startsWith(code[2], "0b")) {
                    imm = stoi(code[2].substr(2));
                }
                else if (startsWith(code[2], "0d")) {
                    imm = stoi(code[2].substr(2), nullptr, 2);
                }

                rs1 = stoi(code[1]);
            }
            if (code[0] == "blz") {
                opcode = 01011;
                rd = 0011;
                if (startsWith(code[2], "0x")) {
                    imm = stoi(hexToBinary(code[2].substr(2)).to_string().substr(15));
                }
                else if (startsWith(code[2], "0b")) {
                    imm = stoi(code[2].substr(2));
                }
                else if (startsWith(code[2], "0d")) {
                    imm = stoi(code[2].substr(2), nullptr, 2);
                }

                rs1 = stoi(code[1]);
            }
            if (code[0] == "bgz") {
                opcode = 01011;
                rd = 0100;
                if (startsWith(code[2], "0x")) {
                    imm = stoi(hexToBinary(code[2].substr(2)).to_string().substr(15));
                }
                else if (startsWith(code[2], "0b")) {
                    imm = stoi(code[2].substr(2));
                }
                else if (startsWith(code[2], "0d")) {
                    imm = stoi(code[2].substr(2), nullptr, 2);
                }

                rs1 = stoi(code[1]);
            }
            if (code[0] == "blez") {
                opcode = 01011;
                rd = 0101;
                if (startsWith(code[2], "0x")) {
                    imm = stoi(hexToBinary(code[2].substr(2)).to_string().substr(15));
                }
                else if (startsWith(code[2], "0b")) {
                    imm = stoi(code[2].substr(2));
                }
                else if (startsWith(code[2], "0d")) {
                    imm = stoi(code[2].substr(2), nullptr, 2);
                }

                rs1 = stoi(code[1]);
            }
            if (code[0] == "bgez") {
                opcode = 01011;
                rd = 0110;
                if (startsWith(code[2], "0x")) {
                    imm = stoi(hexToBinary(code[2].substr(2)).to_string().substr(15));
                }
                else if (startsWith(code[2], "0b")) {
                    imm = stoi(code[2].substr(2));
                }
                else if (startsWith(code[2], "0d")) {
                    imm = stoi(code[2].substr(2), nullptr, 2);
                }

                rs1 = stoi(code[1]);
            }
            if (code[0] == "beq") {
                opcode = 01100;
                rd = 0001;
                rs1 = stoi(code[1]);
                rs2 = stoi(code[2]);
                if (startsWith(code[3], "0x")) {
                    imm = stoi(hexToBinary(code[3].substr(2)).to_string().substr(15));
                }
                else if (startsWith(code[3], "0b")) {
                    imm = stoi(code[3].substr(2));
                }
                else if (startsWith(code[3], "0d")) {
                    imm = stoi(code[3].substr(2), nullptr, 2);
                }
            }
            if (code[0] == "bne") {
                opcode = 01100;
                rd = 0010;
                rs1 = stoi(code[1]);
                rs2 = stoi(code[2]);
                if (startsWith(code[3], "0x")) {
                    imm = stoi(hexToBinary(code[3].substr(2)).to_string().substr(15));
                }
                else if (startsWith(code[3], "0b")) {
                    imm = stoi(code[3].substr(2));
                }
                else if (startsWith(code[3], "0d")) {
                    imm = stoi(code[3].substr(2), nullptr, 2);
                }
            }
        }
    }
    return 0;
}
