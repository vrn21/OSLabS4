touch month

for month in {0..11}
do
        var=$(date -d"+$month Month" +%B)
        echo "$var"
        echo "$var" >> month.txt
done

touch ber_months
ber_month = $(grep ber months.txt)
echo "$ber_month" >> ber_months

cat ber_months
chmod

