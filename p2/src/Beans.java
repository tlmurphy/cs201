public class Beans {

    private int pie;
    private int weed;

	/**
	* Default empty Beans constructor
	*/
	public Beans() {
		super();
	}

	/**
	* Default Beans constructor
	*/
	public Beans(int pie, int weed) {
		super();
		this.pie = pie;
		this.weed = weed;
	}



	/**
	* Returns value of pie
	* @return
	*/
	public int getPie() {
		return pie;
	}

	/**
	* Sets new value of pie
	* @param
	*/
	public void setPie(int pie) {
		this.pie = pie;
	}

	/**
	* Returns value of weed
	* @return
	*/
	public int getWeed() {
		return weed;
	}

	/**
	* Sets new value of weed
	* @param
	*/
	public void setWeed(int weed) {
		this.weed = weed;
	}



	/**
	* Create string representation of Beans for printing
	* @return
	*/
	@Override
	public String toString() {
		return "Beans [pie=" + pie + ", weed=" + weed + "]";
	}
}
