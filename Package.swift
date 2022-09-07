// swift-tools-version: 5.6
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "Chartbeat",
    platforms: [
           .iOS(.v9)
       ],
    products: [
        .library(
            name: "Chartbeat",
            targets: ["Chartbeat"]
        )
    ],
    dependencies: [
    ],
    targets: [
        .binaryTarget(
            name: "Chartbeat",
            path: "Chartbeat.xcframework"
        )
    ]
)
