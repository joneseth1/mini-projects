# Titanic script
using Pkg
Pkg.add(["DataFrames","CSV", "Plots", "DecisionTree", "ScikitLearn"])

using DecisionTree, ScikitLearn.CrossValidation, DataFrames, CSV, Plots


# Turn CSV => DataFrame
train_df = CSV.read("data/train.csv", DataFrame)







