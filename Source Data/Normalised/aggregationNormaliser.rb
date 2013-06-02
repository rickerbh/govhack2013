require 'csv'
require 'json'

# My ruby-fu is weak, but functional.

filenames = ['../Split/Female.csv', '../Split/Male.csv']

# Sourced from http://en.wikipedia.org/wiki/Local_government_areas_of_Victoria
# The "Greater Metro - *" mappings are our own... :-(
areaMapping = {}
areaMapping["Melbourne"] = "Inner Melbourne"
areaMapping["Port Phillip"] = "Inner Melbourne"
areaMapping["Stonnington"] = "Inner Melbourne"
areaMapping["Yarra"] = "Inner Melbourne"
areaMapping["Banyule"] = "Metropolitan"
areaMapping["Bayside"] = "Metropolitan"
areaMapping["Boroondara"] = "Metropolitan"
areaMapping["Brimbank"] = "Metropolitan"
areaMapping["Darebin"] = "Metropolitan"
areaMapping["Glen Eira"] = "Metropolitan"
areaMapping["Hobsons Bay"] = "Metropolitan"
areaMapping["Kingston"] = "Metropolitan"
areaMapping["Manningham"] = "Metropolitan"
areaMapping["Maribyrnong"] = "Metropolitan"
areaMapping["Monash"] = "Metropolitan"
areaMapping["Moonee Valley"] = "Metropolitan"
areaMapping["Moreland"] = "Metropolitan"
areaMapping["Whitehorse"] = "Metropolitan"
areaMapping["Cardinia"] = "Greater Metropolitan - East"
areaMapping["Casey"] = "Greater Metropolitan - East"
areaMapping["Frankston"] = "Greater Metropolitan - South"
areaMapping["Gr. Dandenong"] = "Greater Metropolitan - South"
areaMapping["Hume"] = "Greater Metropolitan - North"
areaMapping["Knox"] = "Greater Metropolitan - East"
areaMapping["Maroondah"] = "Greater Metropolitan - East"
areaMapping["Melton"] = "Greater Metropolitan - West"
areaMapping["Mornington P`sula"] = "Greater Metropolitan - South"
areaMapping["Nillumbik"] = "Greater Metropolitan - North"
areaMapping["Whittlesea"] = "Greater Metropolitan - North"
areaMapping["Wyndham"] = "Greater Metropolitan - West"
areaMapping["Yarra Ranges"] = "Greater Metropolitan - East"

normalised_sla = {}

filenames.each do |filename|

  CSV.foreach(filename, :headers => true) do |row|
    # Make sure the year exists.
    year = normalised_sla[row[0].to_i]
    year = {} if !year

    # Normalise the SLA name down to the major SLA entity
    sla_name = row[2].gsub(/_/, " ").split('-')[0].split('(')[0].strip
    # map sla name to "region"
    sla_name = areaMapping[sla_name]
    # if there is no sla_name (ie, no mapping, ie rural victoria), next please.
    next if !sla_name

    # Make sure the SLA exists
    sla = year[sla_name]
    sla = {} if !sla

    # drop the first 3 elements of the header
    age_headers = row.headers.drop(3)

    # loop through all the age groups and add populations together
    age_headers.each do |age|
      age_i = age.to_i
      population = sla[age_i]
      population = 0 if !population
      row_idx = age_i + 3
      population += row[row_idx].to_f
      sla[age_i] = population
    end

    year[sla_name] = sla
    normalised_sla[row[0].to_i] = year
  end

end

u_normalised = {}
normalised_sla.each do |year, slas|
  u_slas = {}
  slas.each do |sla, ages| 
    max = 0.0
    min = 999999999.0
    # get min/max
    ages.each do |age, population| 
      max = population if population > max
      min = population if population < min
    end

    difference = max - min
    u_ages = {}
    # normalise population numbers
    ages.each do |age, population|
      # guard aganist a divide by 0
      if (difference == 0)
        u_ages[age] = 0
      else
        u_ages[age] = (population - min) / difference
      end
    end
    u_slas[sla] = u_ages
  end
  if (year >= 2013) 
    u_normalised[year] = u_slas
  end
end

output_file = "merged.json"
File.open(output_file,"w") do |f|
  f.write(u_normalised.to_json)
end

puts "Converted and wrote #{output_file}"

