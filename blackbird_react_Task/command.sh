# REPO_URL https://github.com/Alexander040105/BlackBird-Forage-SoftwareEngineering

# Step 1: Create React app
npx create-react-app blackbird_react_Task

# Step 2: Commit code, create GitHub repo
git init
git add .
git commit -m "initial commit"
gh repo create BlackBird-Forage-SoftwareEngineering --public --source=. --push

# Step 3: Switch to update_logo branch
git switch -c update_logo

# Steps 4-5: replaced logo and link in blackbird_react_Task/src/App.js

# Step 6: Commit and push
git add .
git commit -m "changed the logo and the link into propeller logo"
git push origin update_logo

# Step 7: Create PR
gh pr create --title "Pull Request #1" --body "changed the logo and the link into propeller logo"

# Step 8: Merge PR
gh pr merge 1 --merge