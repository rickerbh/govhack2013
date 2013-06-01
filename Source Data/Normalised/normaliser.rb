require 'csv'
require 'json'

# My ruby-fu is weak, but functional.

filenames = ['../Split/Female.csv', '../Split/Male.csv']

filenames.each do |filename|

  normalised_sla = {}

  CSV.foreach(filename, :headers => true) do |row|
    # Make sure the year exists.
    year = normalised_sla[row[0].to_i]
    year = {} if !year

    # Normalise the SLA name down to the major SLA entity
    sla_name = row[2].gsub(/_/, " ").split('-')[0].split('(')[0].strip

    # Make sure the SLA exists
    sla = year[sla_name]
    sla = {} if !sla

    # drop the first 3 elements of the header
    age_headers = row.headers.drop(3)

    # loop through all the age groups and add populations together
    age_headers.each do |age|
      population = sla[age]
      population = 0 if !population
      age_i = age.to_i
      row_idx = age_i + 3
      population += row[row_idx].to_i
      sla[age] = population
    end

    year[sla_name] = sla
    normalised_sla[row[0].to_i] = year
  end

  output_file = filename.split('/').last.split('.csv').last + '.json'
  File.open(output_file,"w") do |f|
    f.write(normalised_sla.to_json)
  end

  puts "Converted and wrote #{output_file}"

end
