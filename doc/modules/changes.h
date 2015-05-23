/**
 * @page changes_current Changes after the latest release (v1.3)
 *
 * <p> This is the list of changes made after the release of Aspect version
 * 1.3. All entries are signed with the names of the author. </p>
 *
 *
 * <ol>
 *
 * <li> The manual.pdf is no longer part of the git repository but you can
 * find it online at http://aspect.dealii.org or you can build it yourself.
 * <br>
 * (Timo Heister, 2015/05/23)
 *
 * <li> New: There are now a set of global constants defined for physical
 * properties and for radius and gravity parameters relevant to 
 * Earth and Mars.
 * <br>
 * (Bob Myhill, 2015/05/22)
 *
 * <li> Changed: The free surface handler now detaches internal manifolds
 * for cases when the domain has them, since they are not necessarily a 
 * good description of the geometry when there has been large mesh deformation.
 * <br>
 * (Ian Rose, 2015/05/21)
 *
 * <li> Changed: The documentation for nullspace removal is now more 
 * descriptive of what Aspect is actually doing. 
 * <br>
 * (Ian Rose, 2015/05/21)
 *
 * <li> Changed: The specific heating plugin has a new interface now; it gets
 * the material model inputs and outputs and fills a vector with heating
 * model outputs for the whole cell.
 * <br>
 * (Juliane Dannberg, 2015/05/20)
 *
 * </ol>
 */
