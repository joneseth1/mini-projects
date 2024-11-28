using DecisionTree, ScikitLearn.CrossValidation, DataFrames, CSV, Random, Statistics

# Turn CSV => DataFrame
train_df = CSV.read("data/train.csv", DataFrame)

# Drop missing values and replace missing Ages with the median
train_df = dropmissing(train_df, "Embarked")
train_df.Age = coalesce.(train_df.Age, 28.0)
train_df = select(train_df, Not("Cabin"))

# Select relevant columns
train_df = select(train_df, Not(["PassengerId", "Name", "Ticket"]))

# Convert Embarked and Sex to numerical values
train_df.Embarked = map(x -> x == "S" ? 1 : (x == "C" ? 2 : 3), train_df.Embarked)
train_df.Sex = map(x -> x == "female" ? 1 : 2, train_df.Sex)

# Split the training set into features (X) and labels (y)
y = train_df[:, "Survived"]
X = Matrix(train_df[:, Not(["Survived"])])

model = RandomForestClassifier(n_trees=100, min_samples_split=10, max_depth=10)
kf = KFold(size(X, 1), n_folds=5, shuffle=true, random_state=42)
accuracy = cross_val_score(model, X, y, cv=kf)

println("Mean Accuracy: $(mean(accuracy))")

