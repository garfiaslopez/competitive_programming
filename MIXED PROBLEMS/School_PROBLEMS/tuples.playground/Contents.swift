//: Playground - noun: a place where people can play

import UIKit

var OptionalArray: Array<(String, String)> = [];

OptionalArray.append((name: "HOLA",lastname: "QUE HACE"));
OptionalArray.append((name: "Que", lastname: "Onda"));
OptionalArray.append((name: "WHATS ",lastname: "UP"));

for op in OptionalArray {
    print(op.0);
}
