<#
for문을 이용해 구구단 출력
#>

$dan = [int](Read-Host "구구단 단수")

Write-Host "구구단" $dan "단"
Write-Host("-"*40)

foreach($hang in (1..9)){
    # $dan * $hang 연산 수행되게 하기 위해서 () 묶음
    Write-Host ($dan , "x", $hang, "=") ($dan*$hang)
}