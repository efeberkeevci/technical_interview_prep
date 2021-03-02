//We will implement a huffman decoder, given encoded message and the huffman table

const encoded_message = "0010111000111011101101110010011010100111001011101011110010000101110";

const A = "00";
const B = "01";
const C = "100";
const D = "101";
const E = "110";
const F = "111";

let i = 0;
let current_bits = "";
let decoded_message = "";

while (i < encoded_message.length) {
    current_bits += encoded_message.charAt(i);
    console.log(current_bits);
    switch (current_bits) {
        case A:
            decoded_message += "A";
            current_bits = "";
            break;

        case B:
            decoded_message += "B";
            current_bits = "";
            break;

        case C:
            decoded_message += "C";
            current_bits = "";
            break;


        case D:
            decoded_message += "D";
            current_bits = "";
            break;

        case E:
            decoded_message += "E";
            current_bits = "";
            break;


        case F:
            decoded_message += "F";
            current_bits = "";
            break;

    }
    i++;
}
console.log(decoded_message);