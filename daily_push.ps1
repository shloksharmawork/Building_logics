# A PowerShell script to commit and push today's DSA solution to GitHub
# Usage: Right-click -> "Run with PowerShell"  OR  run: .\daily_push.ps1

$repoPath = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $repoPath

$date = Get-Date -Format "yyyy-MM-dd"
$commitMsg = "Daily DSA solution - $date"

Write-Host ""
Write-Host "======================================" -ForegroundColor Cyan
Write-Host "  Building_logics — Daily Git Push" -ForegroundColor Cyan
Write-Host "======================================" -ForegroundColor Cyan
Write-Host ""

# Stage all changes
Write-Host "[1/3] Staging all changes..." -ForegroundColor Yellow
git add .

# Show what's being committed
Write-Host ""
Write-Host "Files to be committed:" -ForegroundColor White
git status --short
Write-Host ""

# Commit
Write-Host "[2/3] Committing with message: '$commitMsg'" -ForegroundColor Yellow
git commit -m $commitMsg

# Push
Write-Host ""
Write-Host "[3/3] Pushing to GitHub..." -ForegroundColor Yellow
git push origin main

Write-Host ""
Write-Host "Done! Today's solution is live on GitHub." -ForegroundColor Green
Write-Host "Keep grinding! Day $date complete." -ForegroundColor Green
Write-Host ""
Pause
