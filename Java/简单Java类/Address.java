public class Address {
	private String country;
	private String province;
	private String city;
	private String street;
	private String zipcode;
	public Address() {}
	public Address(String country, String province, String city, String street, String zipcode) {
		this.country = country;
		this.province = province;
		this.city = city;
		this.street = street;
		this.zipcode = zipcode;
	}
	public String getInfo() {
		return "国家: " + this.country +
		"\n省份: " + this.province +
		"\n城市: " + this.city +
		"\n街道: " + this.street +
		"\n邮编: " + this.zipcode;
	}
	public void setCountry(String country)
	{
		this.country = country;
	}
	public void setProvince(String province)
	{
		this.province = province;
	}
	public void setCity(String city)
	{
		this.city = city;
	}
	public void setStreet(String street)
	{
		this.street = street;
	}
	public void setZipcode(String zipcode)
	{
		this.zipcode = zipcode;
	}
	public String getCountry()
	{
		return this.country;
	}
	public String getProvince()
	{
		return this.province;
	}
	public String getCity()
	{
		return this.city;
	}
	public String getStreet()
	{
		return this.street;
	}
	public String getZipcode()
	{
		return this.zipcode;
	}
	
}